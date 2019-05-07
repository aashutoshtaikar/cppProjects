/* Generic Printer using variadic function template 
    Problem : makes multiple copies of the object which affects performance
*/

#include <iostream>

//base case function
void print(){
    std::cout << " .\n"; 
}

/* Passing args by value */
template <class T, class... T_pack>
void print(T val, T_pack... val_pack){
    std::cout << val;
    if(sizeof...(val_pack)) std::cout << ", ";  //can also check sizeof...(T_pack)
    print(val_pack...); //unpacking
} 



int main() {
    print(1,2,'a',5.3,"hello world" , "999");

    return 0;
}

/* In each recursive call the number of args from pack is reduced by 1

1. Print(1,2.5,3,"4");
2. Print(2.5,3,"4");
3. Print(3,"4");
4. Print("4");
5. Print(); //compiler expects a function that does not accept any argument

 */