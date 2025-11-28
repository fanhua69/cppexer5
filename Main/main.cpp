//
//  main.cpp
//  cppexer5
//
//  Created by hua fan on 2025-11-27.
//

//
//  main.cpp
//  testcpp2
//
//  Created by hua fan on 2023-05-28.
//

#include "headers.h"
#include "headers_2.h"
#include "headers_3.h"

int main(int argc, const char * argv[])
{
    system_clock::time_point t1 = system_clock::now();
    time_t tt1 = system_clock::to_time_t(t1);
    printThickLine();
    cout << "Start Time: " << std::ctime(&tt1);
    printThinLine();
    
    tarjan_main();

    printThinLine();
    system_clock::time_point t2 = system_clock::now();
    time_t tt2 = system_clock::to_time_t(t2);
    cout << "End  Time :" << std::ctime(&tt2);
    cout << "Cost Time :" << duration_cast<std::chrono::milliseconds>(t2 - t1)  << endl;
    printThickLine();
    return 0;
}
