#include <iostream>
#include <type_traits>
#include <vector>
#include <list>
#include <deque>
#include <set>
#include <map>
#include <stack>
#include <string>

#ifndef print_vector_h
#define print_vector_h

using namespace std;

// separator stack
struct ps
{
    vector<char> s;
    ps(string str = "") {
        for (char c : str) s.push_back(c);
    }
    size_t size() const { return s.size(); }
    char top() const { return s.back(); }
    void pop() { s.pop_back(); }
};

// --------------------------------------
// Type Traits
// --------------------------------------

template <typename T> struct is_string : std::false_type {};
template <> struct is_string<std::string> : std::true_type {};
template <> struct is_string<const char*> : std::true_type {};
template <> struct is_string<char*> : std::true_type {};

template <typename T> inline constexpr bool is_string_v = is_string<T>::value;

template <typename T> struct is_stack : std::false_type {};
template <typename T1, typename T2> struct is_stack<std::stack<T1, T2>> : std::true_type {};
template <typename T> inline constexpr bool is_stack_v = is_stack<T>::value;

template <typename T> struct is_map : std::false_type {};
template <typename K, typename V, typename C, typename A>
struct is_map<std::map<K, V, C, A>> : std::true_type {};
template <typename T> inline constexpr bool is_map_v = is_map<T>::value;

template <typename T> struct is_pair : std::false_type {};
template <typename A, typename B> struct is_pair<std::pair<A, B>> : std::true_type {};
template <typename T> inline constexpr bool is_pair_v = is_pair<T>::value;

// --------------------------------------
// General print
// --------------------------------------

template <typename T>
void print(const T& value,int layer = 0,  ps separators = ps(""))
{
    char sep = ',';
    if (separators.size()) {
        sep = separators.top();
        separators.pop();
    }
    
    if constexpr (std::is_same<T,bool>::value)
    {
        if(value)
            cout << "True";
        else
            cout << "False";
    }

    else if constexpr (is_string_v<T> || std::is_arithmetic_v<T>)
    {
        std::cout << value;
    }
    else if constexpr (is_pair_v<T>) {
        std::cout << "{";
        print(value.first, layer+1, separators);
        std::cout << ": ";
        print(value.second, layer+1, separators);
        std::cout << "}";
    }
    else if constexpr (is_stack_v<T>) {
        // 打印 stack（top → bottom）
        auto s = value;
        std::cout << "[";
        while (!s.empty()) {
            print(s.top(), layer+1, separators);
            s.pop();
            if (!s.empty()) std::cout << sep;
        }
        std::cout << "]";
    }
    else if constexpr (is_map_v<T>) {
        std::cout << "{";
        auto it = value.begin();
        while (it != value.end()) {
            print(*it, layer+1, separators);
            ++it;
            if (it != value.end()) std::cout << sep;
        }
        std::cout << "}";
    }
    else if constexpr (requires { value.begin(); value.end(); }) {
        // 支持 vector, list, deque, set
        std::cout << "[";
        auto it = value.begin();
        while (it != value.end()) {
            print(*it, layer+1, separators);
            ++it;
            if (it != value.end()) std::cout << sep;
        }
        std::cout << "]";
    }
    else {
        std::cout << value ;  // 不支持的类型
    }
    
    if(layer == 0)
        cout << endl;
}

#endif
