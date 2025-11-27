//
//  daemon.cpp
//  testcpp3
//
//  Created by hua fan on 2025-08-25.
//

#include "headers_2.h"
#include <iostream>
using namespace std;
    

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <time.h>
#include <string.h>

void daemonize()
{
    pid_t pid;
    // 第一次 fork，让父进程退出
    pid = fork();
    if (pid < 0) exit(EXIT_FAILURE);
    if (pid > 0) exit(EXIT_SUCCESS);  // 父进程退出
    // 脱离终端，成为新会话组长
    if (setsid() < 0) exit(EXIT_FAILURE);
    // 第二次 fork，避免重新获得终端
    pid = fork();
    if (pid < 0) exit(EXIT_FAILURE);
    if (pid > 0) exit(EXIT_SUCCESS);  // 第一子进程退出
    // 改变工作目录
    chdir("/");
    // 重设权限掩码
    umask(0);
    // 关闭标准输入输出错误
    close(STDIN_FILENO);
    close(STDOUT_FILENO);
    close(STDERR_FILENO);
}

void daemon_main()
{
    daemonize();
    const char* logfile = "/tmp/mydaemon.log";
    FILE* fp;
    while (1)
    {
        fp = fopen(logfile, "a");
        if (fp)
        {
            time_t now = time(NULL);
            char* timestr = ctime(&now);  // 自带换行符
            timestr[strcspn(timestr, "\n")] = '\0';  // 去掉换行
            fprintf(fp, "[%s] 守护进程正在运行...\n", timestr);
            fclose(fp);
        }
        sleep(10);
    }
    return;
}

