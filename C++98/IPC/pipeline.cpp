//
//  pipeline.cpp
//  testcpp3
//
//  Created by hua fan on 2024-12-21.
//

#include <iostream>
#include <vector>
#include <mutex>
#include <thread>
#include <unistd.h>
#include <chrono>

#include <iostream>
#include <map>
#include <mutex>
#include <thread>
#include <chrono>


using namespace std;

std::mutex mtx_pipe;

int p[2];

bool has_value = false;
string data_pipe  = "";

std::condition_variable cv_pipe;



void write_pipe()
{
    for(int i = 0; i < 5; i++)
    {
        std::unique_lock<std::mutex> lk(mtx_pipe);

        while(has_value == true)
        {
            cv_pipe.wait(lk, [](){return !has_value;});
        }

        write(p[1], "1234", 4);
        data_pipe = "234";
        has_value = true;
        cv_pipe.notify_one();

        std::this_thread::sleep_for(100ms);

    }


}

void read_pipe()
{
    for(int i = 0;i < 5; i++)
    {
        std::unique_lock<std::mutex> lk(mtx_pipe);
        while(!has_value)
        {
            cv_pipe.wait(lk, [](){ return has_value;});
        }

        char s[20];
        read(p[0], s, 20);

        cout << data_pipe << endl;
        cout << s << endl;
        data_pipe = "";

        has_value = false;
        cv_pipe.notify_one();
        std::this_thread::sleep_for(100ms);
    }
}

void pipe_main()
{
    if(pipe(p) < 0 )
        return ;

    std::thread th1(write_pipe);
    std::thread th2(read_pipe);

    th1.join();
    th2.join();

    string s = "abba";


}
