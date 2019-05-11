#pragma once
#include <iostream>

class ComplexNumber {
public:
    float real, im, order;

public:

    ComplexNumber(float r = 0, float i = 0, unsigned int o = 0): real(r),im(i), order(o){}

    ComplexNumber(const ComplexNumber&) = default;
    ComplexNumber& operator=(const ComplexNumber&) = default;
    ComplexNumber(ComplexNumber&&) = default;
    ComplexNumber& operator=(ComplexNumber&&) = default;
    virtual ~ComplexNumber() = default;

    void print(){  //operator<<
        if(im==0) std::cout << real << "\n";
        else if(im>0) std::cout << real << "+" << im << "i\n";
        else std::cout << real << im << "i\n";
    }

};

    ComplexNumber operator+(const ComplexNumber& num1, const ComplexNumber& num2){
        return ComplexNumber(num1.real+num2.real, num1.im+num2.im);
    }

    ComplexNumber operator+(const ComplexNumber& num1, const long double& num2){
        return ComplexNumber(num1.real+num2, num1.im);
    }