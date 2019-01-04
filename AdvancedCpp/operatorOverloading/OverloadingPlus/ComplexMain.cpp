#include<iostream>
#include<stdlib.h>
#include"Complex.h"
using namespace std;
using namespace caveofprogramming;


int main(){
    Complex c1(3,4);
    Complex c2(2,3);

    Complex c3 = c1+c2;                //=assignment operator

    cout << c3 << endl;    //<<overloaded
    
    cout << 1+c1+5+c2+c3 << endl;

    return 0;
}