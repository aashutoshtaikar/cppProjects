#include <iostream>

//base case function
void Print(){}

/* Passing args by reference */
template<typename T, typename...Params> 
void Print(const T &a,const Params&... args){        
    std::cout << a;
    if(sizeof...(args)) std::cout << ',';
    
    Print(args...); 
}


int main()
{
    Print(1,2.5,3,"4");
    return 0;
}

