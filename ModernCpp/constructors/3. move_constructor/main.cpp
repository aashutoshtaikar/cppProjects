#include <iostream>
#include "Integer.h"

//function that returns the sum of 2 integer objects
Integer Add(const Integer& a, const Integer& b){
    Integer temp;
    temp.setValue(a.getValue() + b.getValue());
    return temp;
}

int main(int argc, char const *argv[])
{

    Integer a(1),b(3);
    a.setValue(Add(a,b).getValue());   

    return 0;
}
