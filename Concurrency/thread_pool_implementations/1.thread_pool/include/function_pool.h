/* 
    https://stackoverflow.com/questions/15752659/thread-pooling-in-c11
 */
#pragma once
#include <queue>
#include <functional>
#include <mutex>
#include <condition_variable>
#include <atomic>
#include <cassert>


class Function_pool{
private:
    std::queue<std::function<void()>> m_function_queue;
    std::mutex m_lock;
    std::condition_variable m_data_condition;
    std::atomic<bool> m_accept_functions;

public:
    Function_pool() : m_function_queue(),m_lock(),m_data_condition(),m_accept_functions(true){}
    ~Function_pool(){}

    //producer pushes functions into queue
    void push(std::function<void()> func)
    {
        std::cout <<"\nfrom push_" << std::this_thread::get_id()<<"\n";
        std::unique_lock<std::mutex> lock(m_lock);
        m_function_queue.push(func);

        // when we send the notification immediately, the consumer will try to get the lock , so unlock asap
        lock.unlock();
        
        //producer notifies the consumer to start
        m_data_condition.notify_one();  
    }

    //producer flags done
    void done()
    {
        std::unique_lock<std::mutex> lock(m_lock);
        m_accept_functions = false;
        std::cout <<"\nfrom done_" << std::this_thread::get_id()<<"\n";
        // when we send the notification immediately, the consumer will try to get the lock , so unlock asap
        lock.unlock();
        
        //notify all waiting threads.
        m_data_condition.notify_all();
    }

    //consumer gets function from queue and pops it
    void infinite_loop_func()
    {
        std::function<void()> func;
        while(true){
            {
                std::unique_lock<std::mutex> lock(m_lock);
                //
                m_data_condition.wait(lock, [this]() { return (!m_function_queue.empty() || !m_accept_functions); });
                std::cout << "\n-----" << m_accept_functions << "-----\n";
                
                //exit while
                if (m_function_queue.empty() && !m_accept_functions)
                {
                    return;
                }
                
                func = m_function_queue.front();
                m_function_queue.pop();
            }
            func();
        }
        
    }
};

