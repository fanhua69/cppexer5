//
//  stdexception1.cpp
//  testcpp3
//
//  Created by hua fan on 2025-10-08.
//


#include "headers_2.h"
#include <iostream>
#include <functional>
#include <exception>
#include <stdexcept>

using namespace std;

namespace
{



}

void stdexception1_main()
{
    vector<int> v(10,0);
    try
    {
        std::weak_ptr<int> wp;
        std::shared_ptr<int> sp = wp.lock();
        if(!sp)
        {
            cout << "no ptr" << endl;
        }
        throw std::overflow_error("sdafsdf");
        
        std::shared_ptr<int> sp2(wp);
        
    }
    catch (const std::bad_alloc &e)
    {
        cout << "std::bad_alloc" << endl;
        cout << e.what() << endl;
    }
    catch (const std::out_of_range &e)
    {
        cout << "std::out_of_range" << endl;
        cout << e.what() << endl;
    }
    catch(const std::bad_function_call &e)
    {
        cout << "std::bad_function_call " << endl;
        cout << e.what() << endl;
    }
    catch (const std::bad_typeid &e)
    {
        cout << "bad_typeid" << endl;
        cout << e.what() << endl;
    }
    catch (const std::bad_weak_ptr &e)
    {
        cout << "bad weak ptr" << endl;
    }
    catch (const std::exception &e)
    {
        cout << "std::exception" << endl;
        cout << e.what() << endl;
    }
    catch(...)
    {
        cout << "no know " << endl;
    }
}



