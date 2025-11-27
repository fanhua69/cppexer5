//
//  sfinae12.cpp
//  testcpp3
//
//  Created by hua fan on 2025-10-27.
//


#include "headers_2.h"
#include <iostream>
using namespace std;


//template <typename Float,
//          typename = std::enable_if_t<std::is_floating_point_v<Float>>>
//auto go(const Float value1, const Float value2)
//{
//    return value1+ value2;
//}

//template <typename T>
//typename enable_if<is_floating_point<T>::value, int>::type add(T a, T b)
//{
//    a + b;
//}

//template <typename T>
//typename enable_if<is_floating_point<T>::value, float>::type add(T a, T b)
//{
//    return a + b;
//}

//template <floating_point T>
//float add(T a, T b)
//{
//    return a + b;
//}
//
//template <typename T>
//requires floating_point<T>
//float add( T a , T b)
//{
//    return a + b;
//}

template<typename T>
concept rr = std::is_floating_point_v<T> || std::is_integral_v<T>;

template <typename T>
concept rr2 = requires (T a ) { a ++; };

template <typename T>
concept Addable = requires(T a, T b)
{
    { a + b} -> std::convertible_to<T>;
};

void sfinae12_main()
{
//    add(1.1f,3.1f);
    //cout << go<float>(1.1f,2) << endl;
}
