//
//  ifstreamtest.cpp
//  testcpp3
//
//  Created by hua fan on 2024-11-25.
//


#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include "print.h"
#include <sstream>

using namespace std;

class teststream
{
public:
    teststream(string ss, int age )
    {
        _name = ss;
        _age = age;
    }

    friend ostream & operator << (ostream &o, const teststream &t)
    {
        o << t._name << ", " << t._age;
        return o;
    }
    private:
        string _name;
        int _age;


};

/*
ostream & operator << (ostream &o, const teststream &t)
{
    o << "name:" << t._name << ", age: " << t._age;
    return o;
}*/

void fstream_main()
{
    {
        const char *home = getenv("HOME");
        string path (home);
        path+="/exer/tmp/";
        cout << path << endl;

        ofstream of(path + "mylog.txt", ios::binary);
        size_t s0 =  of.rdstate();
        printb(s0);

        of.clear();
        size_t s = of.rdstate();


        if(of.bad())
        {
            cout << "bad file" << endl;
        }

        if(of.fail())
        {
            cout << "failed " << endl;
        }

        if(of.eof())
        {
            cout << "eof " << endl;
        }


        ios::iostate st;
        of.setstate( ios::badbit | ios::goodbit | ios::failbit | ios::eofbit );
        size_t s3 = of.rdstate();
        printb(s3);

        cout << "good? " << of.good() << endl;

        cout << "good bit:" << ios::goodbit << endl;
        cout << "bad bit:" << ios::badbit << endl;
        cout << "fail bit:" << ios::failbit << endl;
        cout << "eof bit:" << ios::eofbit << endl;



        of.clear();
        {
            of.clear(ios::badbit);
            of.clear(ios::goodbit);
        }

        cout.setf(ios::oct, ios::basefield);
        cout << 34 << endl;

        size_t mask = ios::basefield;
        printb(mask);
        size_t s5 = ~mask;
        printb(s5);

        cout.setf(ios::dec, ios::basefield);
        cout.setf(ios::showbase);
        cout <<  12 << endl;
        cout.width(10);
        cout << 12 << endl;

        int n = 12445;
        of.write((char*)&n, sizeof(n));

        cout << "hex:" << hex << showbase << 16 << endl;;


        of.close();

        ifstream iff(path + "mylog.txt", ios::binary);
        iff.read((char*)&n, sizeof(int));
        cout << n << endl;
        iff.close();


        stringstream ss1;
        istringstream ss("234 2342");
        string sss;
        ss >> sss;
        cout << sss << endl;


    }

    teststream t{"asdfasd", 123};

    cout << t << endl;


}
