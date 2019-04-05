#include <iostream>
#include <string>
#include <thread>
#include <mutex>
#include <functional>
#include <condition_variable>

using namespace std::placeholders;

/* 
Prioritize threads using condition variable notify one
 */
class thread_priority{
public:
    explicit thread_priority():current_thread(0){}

    void wait_and_signal(uint thread_num, void (*funct)(int)){
        std::unique_lock<std::mutex> lock(m_mutex);
        m_cv.wait(lock, [&](){return thread_num == current_thread+1;});  
        
        funct(thread_num);
        
        current_thread++;
        m_cv.notify_one();
    }

private:
    std::mutex m_mutex;
    std::condition_variable m_cv;
    uint current_thread;
};


void somefunc(int tnum){
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    std::cout << "running somefunc from "<< tnum<< "\n";
}

int main(){
    while(1){
    thread_priority te;
    std::thread thread1(&thread_priority::wait_and_signal, &te, 1, somefunc);
    std::thread thread2(&thread_priority::wait_and_signal, &te, 2, somefunc);
    std::thread thread3(&thread_priority::wait_and_signal, &te, 3, somefunc);

    thread1.join();
    thread2.join();
    thread3.join();
    }
    return 0;
}
