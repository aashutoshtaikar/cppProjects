#include <iostream>
#include <thread>
#include <chrono>
#include <condition_variable>
 
void func_1();
void func_2(int &x);
 
void func_2(int &x)
{
    while (true)
    {
        try
        {
            std::cout << x << std::endl;
            std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        }
        catch (...)
        {
            throw std::runtime_error("this is a runtime error");
        }
    }
}
 
void func_1()
{
    int x = 9;
    std::thread thread2(func_2, std::ref(x));
    thread2.detach();
 
    std::this_thread::sleep_for(std::chrono::milliseconds(5000));
    std::cout << "thread 1 finished execution \n";
}
 
int main()
{
    std::thread thread1(func_1);
    thread1.join();
    return 0;
}