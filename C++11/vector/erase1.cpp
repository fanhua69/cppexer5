//
//  erase1.cpp
//  testcpp3
//
//  Created by hua fan on 2024-11-22.
//

#include <vector>
#include <iostream>
#include <list>
#include <set>
#include <map>
#include <utility>
#include <unordered_set>
#include <unordered_map>
#include <iterator>

#include "print.h"

using namespace std;



template <typename ...Ts>
double sum(Ts ... args)
{
   cout << (... + args) << endl;
   cout << (args + ...) << endl;
   cout << (args - ...) <<endl;
   cout << (... - args) << endl;
   cout << (1 + ... + args) << endl;

   return 0;

}

void sss(const std::unordered_map<int,int> &m)
{
    cout << m.at(1) << endl;
}

void remove_main()
{
    std::vector<int> v {1,2,3,3,1,1,1,5,6};
    printc(v);
    v.erase(std::remove(v.begin(), v.end(), 3), v.end());
    v.erase(std::remove_if(v.begin(), v.end(), [](int i){return i == 1;}), v.end());
    printc(v);

    std::list<int> l{1,1,1,2,2,2,3,3,3,4,5};
    printc(l);
    l.remove(1);
    printc(l);

    std::multiset<int> s{1,1,1,2,3,4,5};
    printc(s);
    s.erase(1);
    printc(s);

    std::multimap<int,int> m{{1,2},{1,2},{1,3},{2,4}};
    printc(m);
    m.erase(1);
    printc(m);


    unordered_set<int> ss;
    print(ss.count(1));
    print("sadfsd", 1, 2, 's',222.222);

    sum(9,5,3);

    unordered_map<int, int> mmm;
    mmm.insert({1,      112});
    mmm.insert({1,113});
    mmm.insert({1,224});
    mmm.insert({1,335});
    mmm.insert({2,445});
    mmm.insert({3,556});

    vector<string> sss = {"gfs", "aaa", "ccc", "cccd"};
//    copy(istream_iterator<string>(cin), istream_iterator<string>(), std::back_inserter(sss));
//    copy(sss.begin(), sss.end(), ostream_iterator<string>(cout, ","));


    //copy(istream_iterator<string>(cin), istream_iterator<string>(), ostream_iterator<string>(cout," "));

    vector<string>::reverse_iterator itr = sss.rbegin();
    vector<string>::reverse_iterator itr2 = sss.rend();
    print(*itr);

    vector<string>::iterator it3 = std::min_element(sss.begin(), sss.end());
    print(*it3);



}
