#include<iostream>
#include<thread>

/* 
    properly constructed threads are joinable: pass the callable obj as the arg to the thread class constructor
     default constructor thread obj is non joinable

    after making the call join/detach that thread becomes non-joinable  
    if we forget to join/detach then at the time of destructor call to that thread object std::terminate function will be called
    if a program has std::terminate call -- unsafe program
    
    for safety must check if the thread is joinable or not before calling the join/detach function
    join/detach can be called only once in the threads lifecycle
*/

void isThreadJoinable(const std::thread& thread){
    if(thread.joinable())
        printf("thread is joinable\n");
    else
        printf("thread is not joinable\n");
}

void test(){
    printf("hello from test\n");
}

int main(){
    std::thread thread1(test);
    
    /* joinable member function */

    isThreadJoinable(thread1);
    thread1.join();
    isThreadJoinable(thread1);

    std::thread thread2;
    isThreadJoinable(thread2);

}