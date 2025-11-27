//
//  allocator1.cpp
//  testcpp3
//
//  Created by hua fan on 2025-10-21.
//

#include <iostream>
#include "headers_2.h"
#include <iostream>
using namespace std;


using namespace std;

template<typename T>
class CMyAllocator3
{
public:
    using value_type = T;
    
    CMyAllocator3(){}
    
    T * allocate(std::size_t size)
    {
        if(size == 0)
            return nullptr;
        
        return static_cast<T*> (::operator new (sizeof(T) * size));
    }
    
    void deallocate(T* p, std::size_t size)
    {
        ::operator delete (p);
    }
};


void allocator1_main()
{
    std::vector<int, CMyAllocator3<int>> v;
    v.reserve(5);
    v.push_back(32);
}
