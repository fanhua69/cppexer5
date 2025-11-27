//
//  future_promise.cpp
//  testcpp3
//
//  Created by hua fan on 2025-01-01.
//

#include <mutex>
#include <thread>
#include <iostream>
#include <condition_variable>
#include <variant>

using namespace std;

template <typename T>
class FutureSharedState
{
    public:
        std::mutex mtx;
        std::condition_variable cv;
        bool ready = false;
        std::variant<T, std::exception_ptr> result;

        void set_value(T value)
        {
            std::lock_guard<std::mutex> lock(mtx);
            result = std::move(value);
            cv.notify_all();
        }

        T get_value()
        {
            std::unique_lock<std::mutex> lock(mtx);
            while(!ready)
            {
                cv.wait(lock, [this] { return ready;});
            }

            if(std::holds_alternative<std::exception_ptr>(result))
            {
                std::rethrow_exception(std::get<std::exception_ptr>(result));
            }

            return std::get<T> (result);
        }
};


template <typename T>
class Future_t
{
    std::shared_ptr<FutureSharedState<T>> shared_state;

    public:
        explicit Future_t (std::shared_ptr<FutureSharedState<T>> state) : shared_state (std::move(state)) {}

        T get()
        {
            return shared_state ->get_value();
        }
};

template <typename T>
class Promise_t
{
    std::shared_ptr<FutureSharedState<T>> shared_state;

public:
    Promise_t() : shared_state(make_shared<FutureSharedState<T>>()) {}

    Future_t <T> get_future()
    {
        return Future_<T>(shared_state);
    }

};
