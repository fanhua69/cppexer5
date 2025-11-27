//
//  active_object_pattern2.cpp
//  testcpp3
//
//  Created by hua fan on 2024-12-31.
//



#include <queue>
#include <thread>
#include <mutex>
#include <chrono>
#include <functional>
#include <queue>
#include <iostream>
#include <future>

using namespace std;

class ActiveObjectQueue2
{
public:

    void enqueue(std::function<void()> f)
    {
        std::lock_guard<std::mutex> lg(mt_);
        queue_.push_back(f);
        cv_.notify_one();
    }

    std::function<void()> dequeue()
    {
        std::unique_lock<mutex> ul(mt_);
        while(queue_.empty())
        {
            cv_.wait(ul, [this](){return !queue_.empty();});
        }

        std::function<void()> f = queue_.front();
        queue_.pop_front();
        return f;
    }


private:

    std::deque<std::function<void()>> queue_;
    std::mutex mt_;
    std::condition_variable cv_;

};

class ActiveObject2
{
public:
    ActiveObject2() : done_(false)
    {
        thread_ = std::thread([this]() { this->run();});

    }

    ~ActiveObject2()
    {
        done_ = true;
        auto l = [](int n){};
        submit(l, 1);
        if(thread_.joinable())
            thread_.join();
    }

    template <typename T, typename ... Args>
    auto submit(T&& func, Args&&... args)->std::future<decltype(func(std::forward<Args>(args)...))>
    {
        using ReturnType = decltype(func(std::forward<Args>(args)...));
        auto t = std::make_shared<std::packaged_task<ReturnType()>>
                (std::bind(std::forward<T>(func), std::forward<Args>(args)...));

        std::future<ReturnType> f = t->get_future();

        std::function<void()> ff = [t]() { (*t)();};
//        this->queue_.enqueue([t](){(*t)();});
        this->queue_.enqueue(ff);


        return f;
    }

private:

    void run()
    {
        while(!done_)
        {
            auto f = queue_.dequeue();
            f();
        }
    }

    bool done_;
    ActiveObjectQueue2 queue_;
    std::thread thread_;
};


int add_2(int a, int b)
{
    this_thread::sleep_for(1s);
    return a + b;
}

double devide_2(double a, double b)
{
    this_thread::sleep_for(1s);
    return a / b;
}

void ActiveObjectMain2()
{
    ActiveObject2 ao;
    std::future<int> f1 = ao.submit(add_2, 1, 2);
    std::future<double> f2 = ao.submit(devide_2, 3, 5);
    cout << f1.get() << endl;
    cout << f2.get() << endl;


    char *p=new char [10];
    int *pi = new(p) int [2];
    pi[0] = 11;
    pi[1] = 21;

    for(int i =0; i< 10; i++)
    {
        cout << int( p[i]) << endl;
    }

    vector<int> v1{1,1,2};
    cout << v1.size() << endl;
    vector<int> v2 = std::move(v1);
    cout << v1.size() << endl;
}

