//
//  money.cpp
//  testcpp3
//
//  Created by hua fan on 2024-01-28.
//

#include <stdio.h>
#include "headers.h"
#include <iomanip>
#include <locale>
#include <sstream>
#include <time.h>


void money_main()
{
    string str = "$1.11 $2.22 $3.33";
    cout << std::fixed << std::setprecision(2);

    cout << "\"" << str << "\" parsed with the I/O manipulator:";
    std::istringstream s1(str);

    s1.imbue(std::locale("en_US.UTF-8"));

    long double val;
    while (s1 >> std::get_money(val))
        cout << val / 100 << ' ';

    cout << '\n';

    str = "USD 1,234.56";
    cout << '\"' << str << "\" parsed with the facet directly: " ;
    std::istringstream s2(str);

    s2.imbue(std::locale("en_US.UTF-8"));
    auto &f = std::use_facet<std::money_get<char>>(s2.getloc());
    std::ios_base::iostate err;
    std::istreambuf_iterator<char> beg(s2), end;
    f.get(beg, end, true, s2, err, val);

    cout << val << endl;



    cout << time(0) << endl;

    int n = rand() % 100;
    cout << n << endl;


}
