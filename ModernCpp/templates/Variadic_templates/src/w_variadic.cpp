/* Generic Printer using variadic function template */
#include <iostream>

void print(){
    std::cout << ".\n"; 
}

template <class T, class... T_pack>
void print(T val, T_pack... val_pack){
    std::cout << val;
    if(sizeof...(val_pack)) std::cout << ", ";  //can also check sizeof...(T_pack)
    print(val_pack...); //unpacking
} 



int main() {
    print(1,2,'a',5.3, "hello world", "99999999999999999999999999999999999999");

    return 0;
}