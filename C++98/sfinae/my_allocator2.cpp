//
//  my_allocator2.cpp
//  testcpp3
//
//  Created by hua fan on 2025-10-24.
//


#include "headers_2.h"
#include <iostream>
using namespace std;

namespace
{
template <typename T>
class MyAllocator
{
public:
    using value_type = T;
    
    MyAllocator() noexcept = default;
    
    template<typename U>
    MyAllocator(const MyAllocator<U>&) noexcept
    {}
    
    T * allocate(size_t n) noexcept {
        return static_cast<T*>(::operator new (n * sizeof(T)));
    }
    
    void deallocate(T *p, std::size_t n) noexcept
    {
        ::operator delete(p);
    }
};
}


void my_allocator2_main()
{
}
