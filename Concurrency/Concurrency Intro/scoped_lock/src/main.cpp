#include <iostream>
#include <mutex>
#include <thread>
// #include "scoped_lock.h"

std::mutex m1,m2;

void foo()
{
    std::scoped_lock sc(m1,m2);
    std::cout << "thread1" << '\n';
}

int main()
{
    std::thread thread1(foo);
    std::thread thread2(foo);

    
    thread1.join();
    thread2.join();

    return 0;
}