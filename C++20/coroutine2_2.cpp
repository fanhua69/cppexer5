//
//  coroutine2_2.cpp
//  testcpp3
//
//  Created by hua fan on 2025-01-03.
//

#include <coroutine>
#include <iostream>
#include <optional>
#include <exception>

template <typename T>
struct Generator
{
    struct promise_type
    {
        std::optional<T> current_value;

        Generator get_return_object()
        {
            return Generator{std::coroutine_handle<promise_type>::from_promise(*this)};
        }

        std::suspend_always initial_suspend() { return {}; }
        std::suspend_always final_suspend() noexcept { return {}; }

        std::suspend_always yield_value(T value) {
            current_value = value;
            return {};
        }

        void return_void() {}
        void unhandled_exception() { std::terminate(); }
    };

    std::coroutine_handle<promise_type> handle;

    explicit Generator(std::coroutine_handle<promise_type> h) : handle(h)
    {
    }

    ~Generator()
    {
        if (handle)
            handle.destroy();
    }

    T next()
    {
        handle.resume();
        if (handle.done())
        {
            return T{};
        }

        return *handle.promise().current_value;
    }
};

Generator<int> range(int start, int end)
{
    for (int i = start; i < end; ++i)
    {
        co_yield i; // Yield values one by one
    }
}

int coroutines2_main()
{
    auto gen = range(1, 5);
    for (int i = gen.next(); i != 0; i = gen.next())
    {
        std::cout << i << "\n"; // Output: 1 2 3 4
    }
    return 0;
}
