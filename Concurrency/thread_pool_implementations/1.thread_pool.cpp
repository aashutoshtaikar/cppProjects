/* 
    https://stackoverflow.com/questions/15752659/thread-pooling-in-c11
 */
#include <iostream>
#include <vector>
#include <string>
#include <thread>
#include <mutex>
#include <functional>
#include <condition_variable>
#include <queue>
using namespace std;

typedef function<void()> input_function;

class custom_thread_pool
{
private:
    std::condition_variable condition;
    std::mutex Queue_Mutex; 
    queue<input_function> Queue;
public:
    custom_thread_pool(){}
    ~custom_thread_pool(){}
    
    void infinite_loop_function(){
        input_function Job;
        while(1){
            {
                unique_lock<mutex> lock(Queue_Mutex);
                condition.wait( lock, [&]{return !Queue.empty();} );
                Job = Queue.front();
                Queue.pop();
            }
            Job(); 
        }
    }

    void Add_Job(function<void()> New_Job){
        {
            unique_lock<mutex> lock(Queue_Mutex);
            Queue.push(New_Job);
        }
        condition.notify_one();
    }
    
};




int main()
{
    int num_threads = thread::hardware_concurrency();
    vector<thread> pool;
    custom_thread_pool tp1;
    for(int i = 0; i < num_threads; i++)
    {
        pool.push_back(thread(&custom_thread_pool::infinite_loop_function,tp1));
    }
    return 0;
}