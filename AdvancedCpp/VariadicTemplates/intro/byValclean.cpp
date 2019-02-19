#include <iostream>


//base case function
void Print(){
    std::cout << "\nhere\n";
}

/* Passing args by value */
template<typename T, typename...Params> 
void Print(T a, Params... args){        
    std::cout << a;
    if(sizeof...(args)) std::cout << ", ";
    
    Print(args...); //to access the integral args -- have to use recursion -- need to have a base case
    //without a base case recursion will fail
}




int main()
{
    Print(1,2.5,3,"print anything");
    return 0;
}

/* In each recursive call the number of args from pack is reduced by 1

1. Print(1,2.5,3,"4");
2. Print(2.5,3,"4");
3. Print(3,"4");
4. Print("4");
5. Print(); //compiler expects a function that does not accept any argument

 */