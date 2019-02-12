#include <iostream>

/* need to have arg of  the same type */
// template <typename T>
// void Print(std::initializer_list<T> args){
//     for (const auto &x:args){
//         std::cout << x << " ";
//     }
// }

//base case function
void Print(){}

/* Passing args by value */
template<typename T, typename...Params> //Template parameter pack
void Print(T a, Params... args){        // funtion parameter pack 
    // std::cout << "No of template params "<< sizeof...(Params) << '\n';
    // std::cout << "No of function parameters "<< sizeof...(args) << '\n';
    std::cout << a;
    if(sizeof...(args)) std::cout << ',';
    
    Print(args...); //to access the integral args -- have to use recursion -- need to have a base case
    //without a base case recursion will fail
}




int main()
{
    Print(1,2.5,3,"4");
    return 0;
}

/* In each recursive call the number of args from pack is reduced by 1

1. Print(1,2.5,3,"4");
2. Print(2.5,3,"4");
3. Print(3,"4");
4. Print("4");
5. Print(); //compiler expects a function that does not accept any argument

 */