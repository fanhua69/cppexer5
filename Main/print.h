//
//  print.h
//  testcpp3
//
//  Created by hua fan on 2024-11-23.
//

#include <iostream>


using namespace std;

template<typename T1, typename T2>
ostream & operator << (ostream &o, std::pair<T1, T2> &t)
{
    o << t.first << ", " << t.second << "; ";
    return o;
}

template <typename T, typename T2>
void printc(pair<T, T2> &s)
{
    cout << s.first << " - " << s.second ;
}

// Base template: defaults to false
template <typename T>
struct is_pair : std::false_type {};

// Specialization for std::pair
template <typename T1, typename T2>
struct is_pair<std::pair<T1, T2>> : std::true_type {};

// Helper variable template (C++14 and later)
template <typename T>
constexpr bool is_pair_v = is_pair<T>::value;

template <typename T>
void printc(T &v, string s = "")
{
    if constexpr(std::is_scalar_v<std::decay_t<decltype(v)>>)
        cout <<  v;
    else
    {
        if(is_scalar_v<decay_t<decltype(*v.begin())>>)
            cout << s << ": " ;

        for (auto it = v.begin(); it != v.end(); ++it)
        {
            printc(*it);
            pair<int,int> d{1,2};
            auto vv = *it;

            if(is_scalar_v<decay_t<decltype(*it)>> || is_pair_v<decltype(vv)>)
            {
                if(it != std::prev(v.end()))
                    operator << (cout, string(", "));
            }
        }
        cout << endl;
    }
}

template <typename ...Ts>
void print(Ts... args)
{
    (printc(args), ...);
    cout << endl;
    return;
}

template <typename T>
void printb(T t)
{
    bitset<16> b(t);
    cout << b << " -- " << t << endl;
}
