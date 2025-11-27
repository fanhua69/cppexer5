//
//  mutex_1.cpp
//  testcpp3
//
//  Created by hua fan on 2024-12-20.
//

#include <iostream>
#include <mutex>
#include <thread>
#include "print.h"
    #include <stdio.h>
#include <unistd.h>


char* msg1 = "hello, world #1";
char* msg2 = "hello, world #2";
char* msg3 = "hello, world #3";
#define MSGSIZE 16

using namespace std;


void mutex_1_main()
{

    std::mutex mx;
    mx.lock();
    mx.unlock();
    mx.unlock();
    mx.unlock();
    for(int i = 0; i< 1000;++i)
        mx.unlock();

    print("mutex lock done");



    char inbuf[MSGSIZE];
    int p[2], i;

    /* 打开管道 */
    if (pipe(p) < 0)
        exit(1);

    /* 写入管道 */
    write(p[1], msg1, MSGSIZE);
    write(p[1], msg2, MSGSIZE);
    write(p[1], msg3, MSGSIZE);

    /* 读取管道 */
    for (i = 0; i < 3; i++) {
        read(p[0], inbuf, MSGSIZE);
        printf("%s\n", inbuf);
    }
    return;
}
