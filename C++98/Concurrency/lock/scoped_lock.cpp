//
//  scoped_lock.cpp
//  testcpp3
//
//  Created by hua fan on 2024-01-01.
//

#include <stdio.h>
#include <thread>
#include <mutex>
#include "headers.h"


class user {
public:
    user(const std::string &id) : id_(id)
    {}

    void exchange_infos(user &other)
    {
        std::scoped_lock sl(lock_, other.lock_);
        infos_.swap(other.infos_);
        std::cout << "user id:" << id_ << " exchange user id: " << other.id_ << endl;
    }

private:
    std::string id_;
    std::vector<int> infos_;
    std::mutex lock_;
};

static void exchangeme(user& user1, user & user2)
{
    user1.exchange_infos(user2);
}

void scoped_lock_main()
{
    user user1("user1");
    user user2("user2");
    user user3("user3");
    user user4("user4");

    std::vector<std::thread> threads;
    threads.emplace_back(exchangeme, std::ref(user1), std::ref(user2));
    threads.emplace_back(exchangeme, std::ref(user2), std::ref(user3));
    threads.emplace_back(exchangeme, std::ref(user4), std::ref(user2));
    threads.emplace_back(exchangeme, std::ref(user3), std::ref(user2));
    threads.emplace_back(exchangeme, std::ref(user1), std::ref(user4));

    for(auto &th: threads) {
        if(th.joinable()) {
            th.join();
        }
    }
}

