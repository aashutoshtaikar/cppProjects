#include <iostream>
#include "ComplexNumber.h"

int main() {
    ComplexNumber n1(1,-2), n2(3,4);
    ComplexNumber n3 = 1.0l + ComplexNumber(1,2);
    n3.print();

    return 0;
}