/* using move constructor of a thread class 
    move (4)	thread (thread&& x) noexcept;
*/
#include<iostream>
#include<thread>

void foo(){
    printf("printing from foo\n");
}

void bar(){
    printf("printing from bar\n");
}

int main(){
    std::thread thread1(foo);

    //std::thread thread2 = thread1; //will not work as copy constructor/copy assignnable is deleted
    
    
    std::thread thread2 = std::move(thread1);   //this works, transfers the ownership of t1 to t2
    //thread1 does not own any thread object now
    
    //temporary object (rvalue) in RHS, implicit move call happens, also thread1 did not own any object
    thread1 = std::thread(bar); 

    std::thread thread3(foo);
    thread1 = std::move(thread3);   //thread1 already owns a thread object, program will abort

    thread1.join();
    thread2.join();
    thread3.join();

}