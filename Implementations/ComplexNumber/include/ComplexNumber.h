#pragma once
#include <iostream>

class ComplexNumber {
    float x, y;
public:
    //default constru
    ComplexNumber():x(0),y(0){} 
    
    //param constru
    ComplexNumber(float real, float img): x(real),y(img){}
    
    //alternate copy construc
    // ComplexNumber(const ComplexNumber& num){
    //     x = num.x;
    //     y = num.y;
    // }

    //copy constru
    ComplexNumber(const ComplexNumber& num):x(num.x),y(num.y){}

    //membr functions
    void print(ComplexNumber num){  //operator<<
        if(y==0) std::cout << x << '\n';
        else if(y>0) std::cout << x << '+' << y << 'i\n';
        else std::cout << x << y << 'i\n';
    }

    ComplexNumber add(ComplexNumber num1, ComplexNumber num2){   //operator+
        this->x = num1.x + num2.x;
        this->y = num1.y + num2.y;
        return *this;
    } 

    //operators
    ComplexNumber operator+(const ComplexNumber& num)const{
        ComplexNumber temp;
        temp.add(*this, num);
        return temp;
    }

    //copy assingment
    void operator=(const ComplexNumber& num){
        
    }

    virtual ~ComplexNumber(){}
};