//
//  optional1.cpp
//  testcpp3
//
//  Created by hua fan on 2024-01-27.
//

#include <stdio.h>
#include "headers.h"
#include <optional>


std::optional<int> evenValue(std::vector<int> &d)
{
    for(auto i : d)
    {
        if(i % 2 == 0)
        {
            return std::optional<int>(i);
        }
    }

    return std::optional<int> ();
}

struct teste
{

};

void optional_1_main()
{
    std::vector<int> v  { 1,3};
    std::optional<int> r  = evenValue(v);
    if(r.has_value())
    {
        cout << r.value() << endl;
    }
    else
    {
        try
        {
            try
            {
                cout << r.value() << endl;
            }
            catch (std::bad_optional_access &e)
            {
                cout << e.what() << endl;
                throw 10;
            }
            catch(...)
            {
                cout << "exception" << endl;
            }
            cout << "found no value" << endl;
        }
        catch(int e)
        {
            cout << e << endl;
            cout << "teste" << endl;
        }
    }

    std::optional<int> a(10);
    std::optional<int> b(1);
    std::optional <int > c = a;
    cout << a.value() << endl;

    cout << ( a > b ) << endl;


}
