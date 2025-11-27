//
//  filesystem1.cpp
//  testcpp3
//
//  Created by hua fan on 2025-06-22.
//

#include "headers_2.h"
#include <iostream>
#include <filesystem>

using namespace std;
    
void filesystem1_main()
{
    const string path = "/Users/huafan/";
    std::filesystem::recursive_directory_iterator it(path), itend;
    while(it != itend)
    {
        try{
            cout << it.depth() << endl;
            cout << it->path() << endl;
            ++it;
        }
        catch(const std::filesystem::filesystem_error &e)
        {
            
        }
    }
    
    
}
