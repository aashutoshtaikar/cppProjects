#include <iostream>
using namespace std;

int main(){
    int x = 1;
    int y = 2;
    int z = 3;

    //capture x,y local vars by value
    [x,y](){ cout << x << y << endl;}();

    //capture all local vars by value
    [=](){ cout << x << y << endl;}();

    //capture all local vars by value but y by reference
    [=,&y](){ y = 7; cout << x << y << endl;}();


    //capture all local vars by reference
    [&](){ cout << x << y << endl;}();


    //capture all local vars by reference but not z
    [&,z](){ //z=1; 
    cout << x << y << endl;}();
    
    return 0;
}