
#include<iostream>
using namespace std;

#ifndef COMPLEX_H
#define COMPLEX_H
//implement the copy constructor, real imag, assignment, stream insertion.

namespace caveofprogramming{

class Complex{
private:
    double real;
    double imaginery;

public:
    Complex();

    Complex(Complex &other);

    Complex(double rl, double im);

    const Complex &operator=(const Complex &other);

    friend ostream &operator<<(ostream &out,const Complex &comp);

};

}
#endif