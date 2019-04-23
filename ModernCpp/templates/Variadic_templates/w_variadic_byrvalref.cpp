/* Generic Printer using variadic function template 
    Problem : this solves the pass by val problem but if we test this code with Integer.h
    It doesn't ensure perfect forwarding
*/

#include <iostream>
#include "Integer.h"

void print(){
    std::cout << ".\n"; 
}

template <class T, class... T_pack>
void print(T&& val, T_pack&&... val_pack){
    std::cout << val;
    if(sizeof...(val_pack)) std::cout << ", ";  //can also check sizeof...(T_pack)
    print(std::forward<T_pack>(val_pack)...); //unpacking
}

class test_print{
public:
    static void perfectForwarding(){
        std::cout << Integer{2} << "\n";
        print(1,2,Integer{3});  //now even during recursive call perfect forwarding happens
    }

    static void operatorov(){
        Integer x{1};
        Integer{4} >> x;
        print(x);
    }


    static void normal(){
        print(1,2,'a',5.3,"hello world" , "999");
    }
};


int main() {
    test_print::perfectForwarding();
    // test_print::normal();
    // test_print::operatorov();

    return 0;
}