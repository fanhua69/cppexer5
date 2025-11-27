//
//  purevirtualdestrctor.cpp
//  testcpp2
//
//  Created by hua fan on 2023-09-03.
//

#include <stdio.h>

class purevirtualDestructor
{
public:
virtual ~purevirtualDestructor()=0;
};

purevirtualDestructor::~purevirtualDestructor()
{}

class ff: public purevirtualDestructor
{
public:
~ff(){}

};

ff f;

