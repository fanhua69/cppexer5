//
//  active_object_pattern.cpp
//  testcpp3
//
//  Created by hua fan on 2024-12-30.
//


#include <queue>
#include <iostream>
#include <future>
#include <iostream>
#include <thread>
#include <queue>
#include <functional>
#include <mutex>
#include <condition_variable>
#include <future>


using namespace std;

class ActiveQueue
{
public:
    void enqueue(std::function<void()> f)
    {
        std::lock_guard<std::mutex> lg(mutex_);
        tasks_.push_back(f);
        cv_.notify_one();
    }

    std::function<void()> dequeue()
    {
        std::unique_lock<std::mutex> ul(mutex_);
        while(tasks_.empty())
        {
            cv_.wait(ul, [this](){return !this->tasks_.empty();});
        }

        auto f = tasks_.front();
        tasks_.pop_front();
        return f;
    }


private:
    std::deque<std::function<void()>> tasks_;
    std::mutex mutex_;
    std::condition_variable cv_;

};

class ActiveObject
{
    public:
        ActiveObject() : done_(false)
        {
            worker_ = std::thread([this]() { this->run();});
        }

        ~ActiveObject()
        {
            done_ = true;
            auto l = std::function<void()>([](){});
            queue_.enqueue(l);
            worker_.join();
        }


        template <typename Func, typename ...Args>
        auto submit(Func&& func, Args&&...args)->std::future<decltype(func(args...))>
        {
            using ReturnType = decltype(func(args...));

//            auto task = std::make_shared<std::packaged_task<ReturnType()>>
//            (
//                bind(std::forward<Func>(func), std::forward<Args>(args)...)
//            );


            auto task = std::make_shared<std::packaged_task<ReturnType()>>
            (
                [fu = std::forward<Func>(func), ...as = std::forward<Args>(args)]()
                {
                    return fu(as...);
                }
            );



            std::future<ReturnType> result = task->get_future();
            auto tf = std::function([task](){(*task)();});
            queue_.enqueue(tf);
            return result;
        }

    private:

        ActiveQueue queue_;

        void run()
        {
            while(!done_)
            {
                auto f = queue_.dequeue();
                f();
            }
        }

        std::thread worker_;
        bool done_;

};

int add(int a, int b)
{
    std::this_thread::sleep_for(1s);
    return a+b;
}

int active_object_main()
{
    ActiveObject activeObject;
    auto future1 = activeObject.submit(add, 2,1);
    auto future2 = activeObject.submit(add, 3,5);
    auto future3 = activeObject.submit(add, 3,5);
    auto future4 = activeObject.submit(add, 3,5);
    auto future5 = activeObject.submit(add, 3,5);
    cout << "Task submitted" << endl;

    cout << future1.get() << endl;
    cout << future2.get() << endl;
    cout << future3.get() << endl;
    cout << future4.get() << endl;
    cout << future5.get() << endl;

    return 0;

}
