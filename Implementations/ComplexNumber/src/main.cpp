#include <iostream>
#include "ComplexNumber.h"

int main() {
    ComplexNumber n1(1,2), n2(3,4);
    ComplexNumber n3;
    n3.add(n1,n2);
    return 0;
}