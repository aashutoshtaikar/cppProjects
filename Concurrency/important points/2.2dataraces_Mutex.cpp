#include <iostream>
#include <fstream>
#include <thread>
#include <chrono>
#include <string>
#include <mutex>

#define MAX 100

//race condition inheriting from interface
class Stack 
{ 
    int top; 
public: 
    int a[MAX];    //Maximum size of Stack 
    Stack(): top(-1) {}
    
    bool push(int x){
        if (top >= (MAX - 1))
        {
            std::cout << "Stack Overflow";
            return false;
        }
        else
        {
            a[++top] = x;
            std::cout << x << " pushed into stack\n";
            return true;
        }
    }

    int pop(){
        if (top < 0){
            std::cout << "Stack Underflow";
            return 0;
        }
        else{
            int x = a[top--];
            return x;
        }
    }
    
    bool isEmpty(){
        return (top < 0); 
    }
}; 

// void function1(Stack& stk){
//     int v = stk.pop();
//     v++;
// }

int main() {
    Stack stk;
    // std::thread t1(function1, std::ref(stk));
    // stk.stack_print();
    
    // stk.pop();
    // stk.stack_print();


    // t1.join();

    return 0;
}