#include<iostream>
using namespace std;

//function pointers
void test( void (*pFunc)() ){
    pFunc();
}


int main(){
    auto func = [](){ cout << "hello from lambda" << endl; } ;
    
    func();

    test(func);

    test([](){ cout << "hello from lambda" << endl;});

    return 0;
}
