#include<iostream>
#include<thread>
/*  default (1)		thread() noexcept;
    initialization (2)	template <class Fn, class... Args>explicit thread (Fn&& fn, Args&&... args); 
    copy [deleted] (3)	thread (const thread&) = delete;
    move (4)		thread (thread&& x) noexcept;
*/


void foo(){
    printf("Hello from foo - %d\n",std::this_thread::get_id());
}

class callable_class{
public:
    void operator()(){
        printf("hello from class with function call() operator %d\n", std::this_thread::get_id());
    }
};

int main(){
    std::thread thread1(foo);
    //thread1.join();

    callable_class obj;
    std::thread thread2(obj);

    std::thread thread3([](){
        printf("hello from lambda - %d\n",std::this_thread::get_id());
    });

    thread1.join();
    thread2.join();
    thread3.join();



    printf("hello from main - %d\n", std::this_thread::get_id());

}