//
//  conversion_constructor.cpp
//  testcpp3
//
//  Created by hua fan on 2023-12-31.
//

#include <stdio.h>
#include "headers.h"

class ccc
{
    public:
        ccc(double r)
        {
            cout << "conversion construct ? " << endl;
            m_r = r;
        }

        operator double ()
        {
            return m_r;
        }

        double m_r;
        double m_i;
};


void func(ccc c)
{
    cout << c.m_r << endl;
}

void conversion_constructor_main()
{
    ccc c (1.1);
    //c = 123.23;
    cout << c.m_r << ", " << c.m_i << endl;
    cout << c << endl;

    cout << c + 213 << endl;

    func(1234);


}
