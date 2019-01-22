#include<iostream>
using namespace std;

//arg as function pointers
void test( int (*pFunc)() ){
    pFunc();    //calling the passed function 
}


int main(){
    //will be a type of a functor
    auto func = [](){ cout << "hello from lambda" << endl; } ;
    
    //func();       //calling the function

    // test(func);

    // test([](){ cout << "hello from lambda" << endl;});

    auto func1 = [](){ cout<<"hello from lambda with type int" << endl; return 1;} ;

    test(func1);    //pass using auto

    test([](){cout<<"hello from lambda with type int" << endl; return 1;}); //pass directly

    return 0;
}
