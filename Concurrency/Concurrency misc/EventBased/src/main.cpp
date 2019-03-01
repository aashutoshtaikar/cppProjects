/* source: http://blog.vorbrodt.me/?p=556
Event objects implmented like windows events https://docs.microsoft.com/en-us/windows/desktop/sync/event-objects

*/

#include <iostream>
#include <mutex>
#include <thread>
#include <functional>
#include "Event.hpp"

std::mutex cout_mutex;
#define trace(x){std::scoped_lock<std::mutex> lock(cout_mutex); std::cout << x << '\n';}

const int COUNT = 6;

void manual()
{
    manual_event e; //an event to sync

    //spawn 3 threads
    for (int i = 0; i < COUNT; ++i)
        std::thread([&]() {
            trace("manual " << std::this_thread::get_id() << " blocked");
            e.wait();
            trace("manual " << std::this_thread::get_id() << " unblocked");
        }).detach();

    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    e.signal();
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    e.reset();

    for (int i = 0; i < COUNT; ++i)
        std::thread([&]() {
            trace("manual " << std::this_thread::get_id() << " blocked");
            e.wait();
            trace("manual " << std::this_thread::get_id() << " unblocked");
        }).detach();

    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    e.signal();
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
}

void automatic()
{
    auto_event e; //an event to sync

    for (int i = 0; i < COUNT; ++i)
        std::thread([&]() {
            trace("auto " << std::this_thread::get_id() << " blocked");
            e.wait();
            trace("auto " << std::this_thread::get_id() << " unblocked");
        }).detach();

    for (int i = 0; i < COUNT; ++i)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        e.signal();
    }

    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
}

int main()
{
    // manual();
   while(1)
    automatic();
    //return 0;
}