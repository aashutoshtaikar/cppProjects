#include<iostream>
#include<thread>

/* 
    Join function call introduce a synchronized point between launch thread and the thread that it launched from.
    And it blocks the execution of the thread that calls join function until the launched threads execution finish.

*/

void foo(){
    std::this_thread::sleep_for(std::chrono::milliseconds(5000));
    printf("foo running\n");
}

void bar(){
    std::this_thread::sleep_for(std::chrono::milliseconds(5000)); 
    printf("bar running\n");
}

void test(){
    printf("test running\n");
}

int main(){


    std::thread foo_thread(foo);

    std::thread bar_thread(bar);

    bar_thread.detach();
    /* main thread doesn't have to wait for the bar thread to finish */
    printf("this is after bar thread detach\n");
    
    /* main thread has to wait until foo thread to finish */
    foo_thread.join();
    printf("this is after foo thread join\n");
    
 
}