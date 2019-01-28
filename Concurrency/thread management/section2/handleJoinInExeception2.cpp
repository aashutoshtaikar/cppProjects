#include<iostream>
#include<thread>

/* 
Need a better mechanism for joining: RAII
    Detach can be called as soon as the thread is created however, most of the time we cannot call 
    join function on a thread just after it's been created as it blocks the execution of the (parent)calling thread.

    Try catch method involving thread operation is cumbersome for large projects thus use RAII
    In this method when the thread guard is created it has to join when the destructor is called
*/

void foo(){
    printf("foo running\n");
}

void funcA(){
    printf("funcA running\n");
    throw std::runtime_error("this is a runtime error");
}

class thread_guard{
    std::thread& t;

public:
    explicit thread_guard(std::thread& _t)
        :t(_t){}

    ~thread_guard(){
        if(t.joinable())
            t.join();
    }

    //copy constructor not needed -- must delete or else may cause undersiarable effects
    thread_guard(const thread_guard& t) = delete;

    //copy assignment operator non needed 
    thread_guard operator=(const thread_guard& t) = delete;

};

int main(){

    std::thread foo_thread(foo);
    thread_guard tg(foo_thread);
    
    try{
        funcA();
    }
    catch(...){} 
    /*  when the exception is thrown the main thread will go out of scope
        when it goes out of scope objects created in this function will be destructed
        the tg object calls the destructor and the foo_thread calls join before it is destructed. 
        
        before the call to destructor of the thread object, destructor for thread_guard object will be called.
    */
 
}