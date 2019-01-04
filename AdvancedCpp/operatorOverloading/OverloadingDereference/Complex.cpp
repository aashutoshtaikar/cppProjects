#include"Complex.h"

namespace caveofprogramming{
    Complex::Complex():real(0),imaginary(0){}

    Complex::Complex(const Complex &other){
        real = other.real;
        imaginary = other.imaginary;
    }

    Complex::Complex(double rl, double im):real(rl),imaginary(im){}

    const Complex &Complex::operator=(const Complex &other){
        real = other.real;
        imaginary = other.imaginary;
        return *this;
    }

    double Complex::getReal() const{ 
        return real;
    }

    double Complex::getImaginary() const{
        return imaginary;
    }

    ostream &operator<<(ostream &out,const Complex &comp){
        out << "("<< comp.getReal() << ","<< comp.getImaginary() <<")"  ;
        return out;
    }

    Complex operator+(const Complex &c1, const Complex &c2){
        return Complex(c1.getReal()+c2.getReal(),c1.getImaginary()+c2.getImaginary());
    }

    Complex operator+(const Complex &c1, double d){
        return Complex(c1.getReal()+d,c1.getImaginary());
    }

    Complex operator+(double d,const Complex &c1){
        return Complex(c1.getReal()+d,c1.getImaginary());
    }

    bool Complex::operator==(const Complex &other)const{
        return (real==other.real && imaginary==other.imaginary);
    }

    bool Complex::operator!=(const Complex &other)const{
        return !(real==other.real && imaginary==other.imaginary);
        //OR
        // return !(*this==other);
    }

    Complex operator*(const Complex &c1){
         return Complex(c1.getReal(),-c1.getImaginary());
    }


}

