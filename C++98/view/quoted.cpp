//
//  quoted.cpp
//  testcpp3
//
//  Created by hua fan on 2024-01-25.
//

#include <stdio.h>
#include "headers.h"
#include <iomanip>
#include <string>

void quoted_main()
{
    cout << quoted("Lorem ipsum.") << '\n';
	cout << quoted("Lorem ipsum.", '%') << '\n';
	cout << quoted("100% Lorem ipsum.", '%') << '\n';
	cout << quoted("100% Lorem ipsum.", '%', '+') << '\n';
	cout << '\n';

	// Note that this will give a compilation error 
	// because the `quoted` function doesn't return a string.
	// string a = quoted("Lorem ipsum.", '%');
	// cout << a;

	string one, two, three, four, five;
	cin >> quoted(one); cout << one << '\n';
	cin >> quoted(two); cout << two << '\n';
	cin >> quoted(three, '*'); cout << three << '\n';
	cin >> quoted(four, '*', '&'); cout << four << '\n';
	cin >> quoted(five); cout << five << '\n';

    string s = "asdfsd";
    cout << s << endl;
 }
