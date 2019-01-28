#include<iostream>
#include<thread>

/* 
Need a better mechanism for joining: try,catch blocks
    Detach can be called as soon as the thread is created however, most of the time we cannot call 
    join function on a thread just after it's been created as it blocks the execution of the (parent)calling thread.
*/

void foo(){
    printf("foo running\n");
}

void funcA(){
    printf("funcA running\n");
    throw std::runtime_error("this is a runtime error");
}

int main(){

    std::thread foo_thread(foo);
    
    try{
        funcA();
        foo_thread.join();
    }
    catch(...){
        foo_thread.join();
    }
    
 
}