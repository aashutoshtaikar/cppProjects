#include <iostream>
using namespace std;

//symbolic constants
#define RED 0   //macro
const int GREEN = 1;    //const

//Problem : user can invoke fill color and pass any number as argument
void fillColor_unsafe(int color){
    switch (color){
        case 0:
            cout << "paint with Red\n"; 
            break;
        case 1:
            cout << "paint with Green\n"; 
            break;
    }    
}


//enum use restricted range of values, undefined integral types
enum Color{Red, Green, Blue};   //global DS/BSS

void fillColor(Color color){
    switch (color){
        case Red:
            cout << "paint with Red\n"; 
            break;
        case Green:
            cout << "paint with Green\n"; 
            break;
        case Blue:
            cout << "paint with Blue\n";
            break;
    }   
}

int main() {
    Color c = Red;
    fillColor(c);
    fillColor(Green);
    
    //enum to int
    int x = Green;

    //int to enum
    //fillColor(2); //not allowed
    fillColor(static_cast<Color>(2));   //casting required


    return 0;
}