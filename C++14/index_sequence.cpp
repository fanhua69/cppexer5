//
//  index_sequence.cpp
//  testcpp3
//
//  Created by hua fan on 2024-03-30.
//

#include <stdio.h>
#include "headers.h"
#include <array>
#include "headers.h"

template<typename T, T ... ints>
void ppp(std::integer_sequence<T, ints...> n)
{
    cout << n.size() << endl;
    auto a = {ints...};
}


template<int ...ints>
void ppp()
{
    cout << sizeof...(ints) << endl;

    auto s = std::array{ints...};
    for(auto i : s)
    {
        cout << i << endl;
    }
}

void index_sequence_main_2()
{
   ppp(std::make_integer_sequence<unsigned, 9>{});
   ppp(std::make_index_sequence<9>{});
   auto a = std::make_index_sequence<10>();
   cout << a.size() << endl;

   int aa = 4;
   int ba = std::exchange(aa, 6);
   cout << aa << endl;
   cout << ba << endl;

   std::tuple<int, double> t(1,2.2);
   int i = get<int>(t);
   cout << i << endl;
   int ii = get<0> (t);
   cout << ii << endl;



}
