#include <iostream>

using namespace std;

template<typename T>        //typename can be used instead of class
void samePrint(T n){
    cout << "(from samePrint)other type: " << n << endl;
}

template<class T>
void print(T n){
    cout << "other type: "<< n << endl;
}

template<>
void print(int n){
    cout << "integer type:" << n << endl;
}


int main(){
    samePrint(5);
    print<string>("hello");
    print("hi there");
    print(5);
    return 0;
}


