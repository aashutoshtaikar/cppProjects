#include <iostream>

//base case function
void Print(){}

/* Passing args by Rvalue reference -- perfect forwarding */
template<typename T, typename...Params> 
void Print(T&& a, Params&&... args){        
    std::cout << a;
    if(sizeof...(args)) std::cout << ',';
    
    Print(std::forward<Params>(args)...); 
}


int main()
{
    Print(1,2.5,3,"4");
    return 0;
}

