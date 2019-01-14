#include<iostream>
using namespace std;

class Test{

};

template<class T>
void call(T &&arg){             //due to the T type can accept both L and R values
    check(arg);                 //only calls lvalue 
    check(static_cast<T>(arg)); //calls the right value due to type casting to T
    check(forward<T>(arg));     //forwarding does the same
}

void check(Test &test){
    cout << "lvalue" << endl;
}

void check(Test &&test){
    cout << "rvalue" << endl;
}

int main(){

   // auto &&t = Test();  //Rval ref to Rvalue works

//    Test test;
//    auto &&t = test; //Rval ref to Lval
    
    call(Test());   //passing Rval to call
     

    return 0;
}