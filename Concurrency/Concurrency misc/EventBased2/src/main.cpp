/* source: http://blog.vorbrodt.me/?p=556
Event objects implmented like windows events https://docs.microsoft.com/en-us/windows/desktop/sync/event-objects

*/

#include <iostream>
#include <mutex>
#include <thread>
#include <functional>
#include "Event.hpp"

std::mutex cout_mutex;
#define trace(x)                                       \
    {                                                  \
        std::scoped_lock<std::mutex> lock(cout_mutex); \
        std::cout << x << '\n';                        \
    }


void foo(manual_event& e)
{
    trace("manual " << std::this_thread::get_id() << " blocked");
    e.wait();
    trace("manual " << std::this_thread::get_id() << " unblocked");
}

// void foo(auto_event& e)
// {
//     trace("manual " << std::this_thread::get_id() << " blocked");
//     e.wait();
//     trace("manual " << std::this_thread::get_id() << " unblocked");
// }

void manual()
{
    manual_event e; //an event to sync

    std::thread thread1(foo,std::ref(e));
    thread1.detach();
    std::thread thread2(foo,std::ref(e));
    thread2.detach();

    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    e.signal();
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    e.reset();
}

// void automatic()
// {
//     auto_event e; //an event to sync

//     std::thread thread1(foo,std::ref(e));
//     thread1.detach();
//     std::thread thread2(foo,std::ref(e));
//     thread2.detach();
    
//     std::this_thread::sleep_for(std::chrono::milliseconds(1000));
//     e.signal();
//     std::this_thread::sleep_for(std::chrono::milliseconds(1000));
//     e.signal();
//     std::this_thread::sleep_for(std::chrono::milliseconds(1000));
// }

int main()
{
    manual();
    //automatic();
    return 0;
}