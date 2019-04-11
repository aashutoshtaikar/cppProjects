/*  passing value from a child to parent
    std::future , std::async basics
 */
#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>
#include <future>

int factorial(int n){
    
    if (n==1) {
        std::cout << "child thread:" << std::this_thread::get_id() << "\n";
        return 1;
    }
    else{
        return n * factorial(n-1); 
    }
}

int main() {
    std::cout << "Parent thread:"<<std::this_thread::get_id() <<"\n";
    int x = 0;
    std::future<int> fu = std::async(factorial,4);                       //default, decides as per the implementation
    // std::future<int> fu = std::async(std::launch::deferred,factorial,4); //deffer till the get function is called (same thread)
    // std::future<int> fu = std::async(std::launch::async,factorial,4);    //creates another thread runs function
    // std::future<int> fu = std::async(std::launch::deferred | std::launch::async, factorial, 4); //same as default
    x = fu.get();
    std::cout << "Parent thread: value received from child thread:" << x << "\n"; 

    return 0;
}