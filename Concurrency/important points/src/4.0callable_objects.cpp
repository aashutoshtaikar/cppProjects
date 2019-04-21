#include <iostream>
#include <stdlib.h>
#include <future>
using namespace std;

class A{
public:
    void func(int x, char c){
        cout << x << c << "\n";
    }
    
    void p_func(int* x){
        cout << *x << "\n";
    }
    
    int operator()(int n){
        cout << n << "\n";    
        return 0;
    }
};

int func(int x){
    cout << x << "\n";
}

int main(){
    A a;                        //functor a()
    std::async(a, 1);           //copy of functor a() in a different thread
    // std::async(std::ref(a), 2); //functor a() in a different thread
    // std::async(A(), 3);         //temp obj of A
    
    // std::async(&A::func, a, 4, 'h');  //copy of a
    // std::async(&A::func, &a, 5, 'c'); //ref of a

    std::thread t1(std::move(a), 6); // warning: a will be moved to child thread and destructed there
    t1.join();
    
    std::thread t2(std::ref(a), 7);
    t2.join(); 

    std::async([](int x){
        cout << x << "\n";
        return x*x;}, 
    8);

    //int x = 3;
    void* pz = (int*)malloc(sizeof(int)*2);
    ((int*)pz)[0] = 21;

    int* x = (int*)pz;
    x[1] = 22;

    printf("%d,%d",((int*)pz)[0], x[1]);
 
    // func(&temp);
    return 0;
}