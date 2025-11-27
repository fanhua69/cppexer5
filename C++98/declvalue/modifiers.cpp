//
//  modifiers.cpp
//  testcpp3
//
//  Created by hua fan on 2025-07-22.
//

#include "headers_2.h"
#include <iostream>
#include <algorithm>

using namespace std;

   
void modifiers_main()
{
    vector<int> v{1,2,3,4,5,6,7};
    vector<int> t;
    std::copy(v.begin(), v.end(), std::back_inserter(t));
    print(t);
    
    std::copy_backward(v.begin(),v.begin() + 2 , t.begin() + 4);
    
    cout<<endl;
    print(t);
    
    std::copy_if(v.begin(),v.end(), t.begin(),[](int x){ return  x > 5;});
    print(t);
    
    std::copy_n(v.begin(), 4, t.begin());
    print(t);
    
    std::fill(t.begin(), t.end(), 111);
    print(t);
    
    std::fill_n(t.begin(), 4, 113);
    print(t);
    
    std::generate(t.begin(), t.end(), [](){return 1234;});
    print(t);
    
    std::generate_n(t.begin(), 3, [](){return 333;});
    print(t);
    
    std::iter_swap(v.begin(), v.begin() + 3);
    print(v);
    
    vector<int> vr {1,2,2,2,2,3,4,5,6};
    vr.erase(std::remove(vr.begin(), vr.end(), 2), vr.end());
    print(vr);
    
    vector<int> vu { 1,2,3,3,9, 4,4,4,5,6,7,7,7};
    std::sort(vu.begin(), vu.end());
    print(vu);

    auto itu = std::unique(vu.begin(), vu.end());
    print(vu);

    vu.erase(itu, vu.end());
    print(vu);
    
    map<int, vector<pair<int,int>>> m;
    m[0]= {{1,2},{3,4}};
    m[1]= {{11,21},{31,41}};
    
    print(m);
    
    
    
}
