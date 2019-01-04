#include <iostream>

using namespace std;

template<class T>
void print(T n){
    cout << "Template Version: " << n << endl;
}

void print(int value){
    cout << "Non-Template version: " << value << endl;
}

template<class T>
void show(){
    cout << T() << endl;
}

int main(){
    print<string>("hello");
    show<double>();

    return 0;
}
