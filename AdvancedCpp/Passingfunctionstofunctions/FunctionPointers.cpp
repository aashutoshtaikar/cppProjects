#include <iostream>
using namespace std;
// pointer to a function
// virtual functions implicitly creates VTABLE/virtual table consisting of function pointers

void test(){
    cout << "hello" << endl;
}

void testVal(int value){
    cout << "hello: "<< value << endl;
}

int main(){
    void (*pTest)(); //void pointer
    pTest = &test;  //() are calling operator so not used here

    //calling the function using function pointer
    (*pTest)();
    pTest();




    (*test)();
    test();

    return 0;
}
