//
//  emplace_back.cpp
//  testcpp3
//
//  Created by hua fan on 2024-02-21.
//

#include <stdio.h>
#include "headers.h"

class emplace_test
{
public:
    emplace_test(int num) : num(num)
    {
        cout << num << endl;
        cout << "constructor..." << endl;
    }

    emplace_test(const emplace_test &other) : num(other.num)
    {
        cout << num << endl;
        print("copy constructor...");
    }

    emplace_test(emplace_test &&other) : num(other.num)
    {
        cout << num << endl;
        print("move copy constructor...");
    }

    int num;
};

void emplace_back_main()
{
    print("=====================");
    print("emplace_back");
    vector<emplace_test> v;
    v.emplace_back(3);

    print("=====================");
    print("push_back");
    vector<emplace_test> v2;
    v2.push_back(2);

    vector<int> demo1{1,2};
    vector<int> demo2{3,4};

    demo1.emplace(demo1.end(), 3);
    demo1.insert(demo1.begin()+1,  demo2.begin(), demo2.end());
    print(demo1);


    cout << endl;
    demo1.erase(std::remove(demo1.begin(), demo1.end(), 3),demo1.end());
    print(demo1);

}
