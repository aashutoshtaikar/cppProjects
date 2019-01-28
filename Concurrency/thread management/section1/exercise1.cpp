#include<iostream>
#include<thread>

int main(){
    std::thread thread1([](){
        printf("funcA running - %d\n",std::this_thread::get_id());

        std::thread thread3([](){
            printf("hello from test - %d\n",std::this_thread::get_id());
        });
        thread3.join();
    });

    

    std::thread thread2([](){
        printf("funcB running - %d\n",std::this_thread::get_id());
    });

    thread1.join(); 
    thread2.join();

    printf("hello from main - %d\n",std::this_thread::get_id());
}