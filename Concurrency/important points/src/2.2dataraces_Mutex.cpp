#include <iostream>
#include <fstream>
#include <thread>
#include <chrono>
#include <string>
#include <mutex>

//stack example
class Stack{
    int* m_data;
    std::mutex m_mu;
public:
 
    Stack(){
        m_data = new int[2]{1,2};
    }

    //pops off the item from top of the stack  
    void pop(){
        std::lock_guard<std::mutex> m_mu();
        m_data[sizeof(m_data)/sizeof(*m_data) - 1] = 0; 
    }   

    //returns the item on top
    int& top(){
        return m_data[sizeof(m_data)/sizeof(*m_data) - 1];
    }  

    void stack_print(){
        for(size_t i = 0; m_data[i] ; i++)
        {
            std::cout << m_data[i] << ' '; 
        }
        std::cout << '\n';
    }
};

// void function1(Stack& stk){
//     int v = stk.pop();
//     v++;
// }

int main() {
    Stack stk;
    // std::thread t1(function1, std::ref(stk));
    stk.stack_print();
    
    // stk.pop();
    // stk.stack_print();


    // t1.join();

    return 0;
}