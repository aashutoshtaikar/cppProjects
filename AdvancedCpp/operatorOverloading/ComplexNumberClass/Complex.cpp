#include"Complex.h"

namespace caveofprogramming{
    Complex::Complex():real(0),imaginery(0){}

    Complex::Complex(Complex &other){
        real = other.real;
        imaginery = other.imaginery;
    }

    Complex::Complex(double rl, double im):real(rl),imaginery(im){}

    const Complex &Complex::operator=(const Complex &other){
        real = other.real;
        imaginery = other.imaginery;
        return *this;
    }

    std::ostream &operator<<(std::ostream &out,const Complex &comp){
        out << comp.real << "+" << comp.imaginery <<"i" ;
        return out;
    }

};

