
#include<iostream>
#include<vector>
#include<string>

using namespace std;

#ifndef COMPLEX_H
#define COMPLEX_H
//implement the copy constructor, real imag, assignment, stream insertion.

namespace caveofprogramming{

class Complex{
private:
    double real;
    double imaginary;

    
public:
    Complex();

    Complex(const Complex &other);

    Complex(double rl, double im);

    const Complex &operator=(const Complex &other);

    double getReal() const;

    double getImaginary() const;

    bool operator==(const Complex &other)const; 
    bool operator!=(const Complex &other)const;
};
    ostream &operator<<(ostream &out,const Complex &comp);  //free function
    Complex operator+(const Complex &c1, const Complex &c2);
    Complex operator+(const Complex &c1, double d);
    Complex operator+(double d,const Complex &c1);
    Complex operator*(const Complex &c1);
}
#endif