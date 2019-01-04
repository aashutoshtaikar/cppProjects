#include<iostream>
#include<stdlib.h>
#include"Complex.h"
using namespace std;
using namespace caveofprogramming;


int main(){
    Complex c1(3,4);
    Complex c2(2,3);
    cout << (*c1) + *Complex(4,3) << endl;

    return 0;
}