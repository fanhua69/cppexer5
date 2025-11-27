//
//  decode_fix.cpp
//  testcpp3
//
//  Created by hua fan on 2025-10-21.
//



#include "headers_2.h"
#include <iostream>
#include <unordered_map>

using namespace std;




void process_pair(unordered_map<int, string> &m, std::string_view pd)
{
    size_t p = pd.find('=');
    if(p != string::npos)
    {
        string key = string(pd.substr(0, p));
        string value = string(pd.substr(p+1));
        m[stoi(key)] = value;
    }
}

void decode_fix_main()
{
    std::string raw = "8=FIX.4.2|9=112|35=D|49=BUY1|56=SELL1|34=215|52=20190614-09:30:05.250";
    
    std::unordered_map<int, string> m;

    size_t current_pos = 0;
    while(current_pos < raw.size())
    {
        size_t p = raw.find('|', current_pos);
        if(p == std::string::npos)
        {
            p = raw.size();
        }
        string pd = raw.substr(current_pos, p - current_pos);
        process_pair(m, pd);
        current_pos = p + 1;
    }
    
    for(auto [key, value] : m)
    {
        cout << key << ", " << value << endl;
    }
}
