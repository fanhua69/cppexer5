//
//  active_object_pattern3.cpp
//  testcpp3
//
//  Created by hua fan on 2025-01-01.
//

#include <iostream>
#include <mutex>
#include <condition_variable>
#include <thread>
#include <queue>
#include <functional>
#include <future>
#include <utility>

using namespace std;


class ActiveObjectQueue3
{
    public:
        void enqueue(std::function<void()> f)
        {
            std::lock_guard<std::mutex> lg(mutex_);
            queue_.push_back(f);
            cv_.notify_one();
        }

        std::function<void()>  dequeue()
        {
            std::unique_lock<mutex> lg(mutex_);
            while(queue_.empty())
            {
                cv_.wait(lg, [this](){return !queue_.empty();});
            }

            std::function<void()> f = queue_.front();
            queue_.pop_front();
            return f;
        }

    protected:
        std::mutex mutex_;
        std::condition_variable cv_;
        std::deque<std::function<void()>> queue_;
};

class ActiveObject3
{
public:
    ActiveObject3(): done_(false)
    {
        thread_ = std::thread([this]() { this->run();});
    }

    ~ActiveObject3()
    {
        done_ = true;
        if(thread_.joinable())
        {
            thread_.join();
        }
        submit([](){});
    }

    void run()
    {
        while(!done_)
        {
            std::function<void()> f = queue_.dequeue();
            f();
        }
    }

    public:
        template <typename Func, typename... Args>
        auto submit(Func&& func, Args&&... args) -> std::future<decltype(func(args...))>
        {
            using ReturnType = decltype(func(args...));

            auto t    = std::make_shared<std::packaged_task<ReturnType()>>
            (
                [fu = std::forward<Func>(func), ...a = std::forward<Args>(args)]()
                {
                    return fu(a...); //std::forward<Args>(a)...);
                }
            );

            
            std::future<ReturnType> fu = t->get_future();

            std::function<void()> f = [t, args...]() {(*t)();};

            queue_.enqueue(f);
            return fu;
        }



    protected:
        ActiveObjectQueue3 queue_;
        bool done_;
        std::thread thread_;
};


int add_3(int a, int b)
{
    std::this_thread::sleep_for(1s);
    return a + b;
}

void ActiveObject3_main()
{
    ActiveObject3 a;
    auto f1 = a.submit(add_3, 1,3);
    auto f2 = a.submit(add_3, 3,3);
    cout << f1.get() << endl;
    cout << f2.get() << endl;


}
