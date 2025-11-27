//
//  deletedFunctions.cpp
//  testcpp3
//
//  Created by hua fan on 2024-11-13.
//

#include <iostream>
#include <map>

using namespace std;


class OpenFile
{
public:

    OpenFile(string filename)
    {
        m_name = filename;
        cout << "open a file:" << filename  << endl;
    }
    OpenFile()
    {
        int m = 0;
    };
    OpenFile & operator = ( const OpenFile&o)
    {
        //int m=0;
        return *this;
    }

    OpenFile(const OpenFile &o)
    {
        int m = 0;
    }

    OpenFile(const OpenFile &&o)
    {
        //m_name = std::move(o.m_name);

    }
    OpenFile(OpenFile &&o)
    {
        //m_name = std::move(o.m_name);

    }
    OpenFile(OpenFile &o)
    {
        //m_name = std::move(o.m_name);

    }
    OpenFile & operator = (const OpenFile &&o)
    {
        //int m = 0;
        return *this;
    }
    string m_name;
};

void deletedFunctionsMain()
{
    OpenFile f(OpenFile("test file"));
    cout << f.m_name << endl;
}
