#include<iostream>
using namespace std;

int main(){
    int x = 1;

    [x]()mutable{
        x = 2;
    };

    return 0;
}