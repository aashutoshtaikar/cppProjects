#include <iostream>
#include "Integer.h"



int main(int argc, char const *argv[])
{
    int *p1 = new int(5);
    //shallow copy
    int *p2 = p1;

    //deep copy -- copy the value rather than the address of the pointer
    int *p3 = new int(*p1);



    Integer i(5);   
    Integer i2(i); //invoking copy constructor -- works but dangerous due to copying of pointers
    i2 = i; // creates a copy -- even tho not defined default copy assignment operator works here -- but shallow copy only
    
    std::cout << i.getValue() << std::endl;

    return 0;
}
