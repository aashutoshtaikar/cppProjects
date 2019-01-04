#include<iostream>
#include<stdlib.h>
#include"Complex.h"
using namespace std;
using namespace caveofprogramming;

// class Complex{
//     private:
//     double real,imaginery;
//     public:
//     Complex():real(0),imaginery(0){}

//     Complex(Complex &other){
//         real = other.real;
//         imaginery = other.imaginery;
//     }

//    Complex(double rl, double im):real(rl),imaginery(im){}

//     const Complex &operator=(const Complex &other){
//         real = other.real;
//         imaginery = other.imaginery;
//         return *this;
//     }

//     friend ostream &operator<<(ostream &out,const Complex &comp){
//         out << comp.real << "+" << comp.imaginery <<"i" ;
//         return out;
//     }

// };

int main(){
    Complex c1(2.0,3.0);
    Complex c2 = c1;

    //c1 = c2;

    cout << c1 << endl;

    return 0;
}