/* 
    Synchronization of tasks in  between threads in a sample application using condition variable
 */
#include <iostream>
#include <string>
#include <functional>
#include <thread>
#include <condition_variable>
#include <mutex>

using namespace std::placeholders;

class Application
{
private:
    std::mutex m_mutex;
    std::condition_variable m_condVar;
    bool m_bDataLoaded;
public:
    Application():m_bDataLoaded{false}{}
    
    bool isDataLoaded(){
        return m_bDataLoaded;
    }
    
    void loadData(){
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        std::cout << "Loading data from XML\n";
        std::lock_guard<std::mutex> data_struct_lock(m_mutex);
        m_bDataLoaded = true;
        m_condVar.notify_one();
    }

    void mainTask(){
        std::cout << "Do some handshaking with the server\n";
        std::unique_lock<std::mutex> ulock(m_mutex);
        m_condVar.wait(ulock, std::bind(&Application::isDataLoaded,this));  //wait for the data to be loaded by loader_thread
        m_condVar.notify_one();
        std::cout << "Do processing over loaded data\n";
    }
};


int main(){
    
    Application app;
    std::thread main_thread(&Application::mainTask,&app);
    std::thread loader_thread(&Application::loadData,&app);
    main_thread.join();
    loader_thread.join();
    
    return 0;
}
