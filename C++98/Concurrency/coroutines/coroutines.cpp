//
//  coroutines.cpp
//  testcpp3
//
//  Created by hua fan on 2025-01-02.
//


#include <coroutine>

#include <iostream>

using namespace std;

#include <concepts>
#include <coroutine>
#include <exception>
#include <iostream>
#include <ranges>
#include <algorithm>
#include <vector>


struct ReturnObject_a
{
  struct promise_type
  {
    ReturnObject_a get_return_object() { return ReturnObject_a(); }
    std::suspend_never initial_suspend() { return suspend_never(); }
    std::suspend_never final_suspend() noexcept { return suspend_never(); }
    void unhandled_exception() { cout << " excpetion" << endl;}
  };
};

struct Awaiter_b
{
  std::coroutine_handle<> *hp_;
  constexpr bool await_ready() const noexcept { return false; }
  void await_suspend(std::coroutine_handle<> h) {*hp_ = h; }
  constexpr void await_resume() const noexcept {}
};

ReturnObject_a counter(std::coroutine_handle<> *continuation_out)
{
  Awaiter_b a{continuation_out};
  for (unsigned i = 0;; ++i)
  {
    co_await a;
    std::cout << "counter: " << i << std::endl;
  }
}


void coroutine_main()
{
  std::coroutine_handle<> h;

  counter(&h);

  for (int i = 0; i < 3; ++i)
  {
    std::cout << "In main1 function\n";
    h();
  }

  std::vector<int> a{1,2,3,4,5,6,7};
  auto v = std::ranges::count_if(a.begin(), a.end(), [](int s){return s < 3;});
  cout << v << endl;

  h.destroy();
}

