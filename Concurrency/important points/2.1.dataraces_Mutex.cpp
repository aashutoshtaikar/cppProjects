#include <iostream>
#include <fstream>
#include <thread>
#include <chrono>
#include <string>
#include <mutex>

//more realistic example to protect file write
class LogFile{
    std::mutex m_mutex;
    std::ofstream m_file;
public:
    LogFile(){
      m_file.open("3.log.txt");
    }

  void shared_print(std::string msg, int id){
    std::lock_guard<std::mutex> guard(m_mutex);
    m_file << msg <<':' <<  id << "\n";
  }

  ~LogFile(){
    m_file.close();
  }

    /* never return m_file to the outside world */
    // std::ofstream& getStream() {return m_file;}

    /* never pass m_file as an argument to user provided function */
    // void process_file(void user_func(std::ofstream&)){
    //     user_func(m_file);
    // }
};

void function1(LogFile& log){
    for(int i = 0; i >- 10; i--){
        std::this_thread::sleep_for(std::chrono::seconds(1));
        log.shared_print(std::string("From t1: "), i);
    } 
}

int main() {
    LogFile log;
    std::thread t1(function1, std::ref(log));

    for(int i = 0; i < 10; i++){
        std::this_thread::sleep_for(std::chrono::seconds(1));
        log.shared_print(std::string("From main: "), i);
    }

    t1.join();

    return 0;
}