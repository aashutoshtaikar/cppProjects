#include <iostream>
#include <thread>
#include <chrono>
#include <string>
#include <mutex>

std::mutex mu;

//however the mutex will still be able to access the cout as it is global 
void shared_print(std::string msg,int id){
    std::lock_guard<std::mutex> guard(mu);
    // mu.lock();
    std::cout << msg << id << std::endl;
    // mu.unlock();
}

void function1(){
    for(int i = 0; i >- 10; i--)
    {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        shared_print(std::string("From t1: "),i);
    }
    
}

int main() {

    std::thread t1(function1);

    for(int i = 0; i < 10; i++){
        std::this_thread::sleep_for(std::chrono::seconds(1));
        shared_print(std::string("From main: "),i);
    }

    t1.join();

    return 0;
}