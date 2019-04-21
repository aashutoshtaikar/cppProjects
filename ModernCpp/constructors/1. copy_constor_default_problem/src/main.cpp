#include <iostream>
#include "Integer.h"

void print(Integer i){
//default compiler generated copy constructor invoked due to arg passed by value
}

Integer Add(int x, int y){
    return Integer(x+y);    //default copy constructor invoked due to returning by value
}

int main(int argc, char const *argv[])
{
    Integer i(5);   
    Integer i2(i); //invoking copy constructor -- works but dangerous due to copying of pointers(shallow copy) 
    std::cout << i.getValue() << std::endl; //shallow copy (same address for both i and i2)
    //to avoid the problems due to shallow copy -- need to implement a user defined copy constr
    return 0;
}
 