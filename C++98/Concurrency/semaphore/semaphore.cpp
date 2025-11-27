//
//  semaphore.cpp
//  testcpp3
//
//  Created by hua fan on 2024-01-27.
//

#include <stdio.h>

// Parking Lot

#include <semaphore>
#include <string>
#include <vector>
#include "headers.h"
#include <thread>
#include <random>
#include <shared_mutex>
#include <mutex>

std::deque<std::string> cars_in_parking_lot;
int parking_lot_size = 5;
std::counting_semaphore sema_lot(parking_lot_size);

std::mutex mtxlot;
std::shared_mutex mutex_lot_shared;
std::vector<string> cars = {};
std::atomic_bool cars_done = false;
std::binary_semaphore sema_cars{0};
std::mutex mutex_out;

void out (std::string s)
{
    std::unique_lock<std::mutex> lock_out(mutex_out);
    cout << s << endl;
}

void creating_cars()
{
    std::this_thread::sleep_for(chrono::seconds(3));

    out ("Creating cars ... ");

    for(int i = 0 ; i< parking_lot_size  * 2; i ++)
    {
        cars.push_back("car"+std::to_string(i));
    }

    out ("Creating cars Done. ");

    sema_cars.release();
}

void incoming_cars()
{
    sema_cars.acquire();

    out("Parking cars into lot...");

    while(cars.size())
    {
        this_thread::sleep_for(chrono::milliseconds(1));
        {
            if(sema_lot.try_acquire())
            {
                std::unique_lock<std::mutex> lock_lot(mtxlot);
                string car = cars.back();
                cars.pop_back();
                out ("car : " + car + " is parked.");
                cars_in_parking_lot.push_back(car);
            }
            else
            {
                out("waiting parking lot ....... ");
            }
        }
    }

    cars_done.store(true, std::memory_order_release);
    cars_done.notify_all();
}

void parking_lot()
{
    while(true)
    {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        {
            std::lock_guard<std::mutex> lock(mtxlot);
            if(cars_in_parking_lot.size())
            {
                auto car = cars_in_parking_lot.front();
                cars_in_parking_lot.pop_front();
                out ("car : " + car + " is left");
                sema_lot.release();
            }
        }

        if(cars_done.load(std::memory_order_acquire) && cars_in_parking_lot.size() == 0)
        {
            break;
        }
    }
}

void parking_lot_main()
{
    std::thread create_cars_thread(creating_cars);
    std::thread incoming_cars_thread(incoming_cars);
    std::thread lot_thread(parking_lot);

    create_cars_thread.join();
    incoming_cars_thread.join();
    lot_thread.join();
}

