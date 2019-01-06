#include <iostream>
using namespace std;
// pointer to a function
// virtual functions implicitly creates VTABLE/virtual table consisting of function pointers
// virtual keyword creates a VTABLE

void test(){
    cout << "hello" << endl;
}

void testVal(int value){
    cout << "hello: "<< value << endl;
}

int main(){
    //declaring a function pointer
    void (*pTest)(); //void pointer to a function
    //pTest = &test();  //() are calling operator so should not be used here
    
    pTest = &test;      // defining addr of test //OR
    pTest = test;       // name of the function is pointer to that function
    
    //calling the function using function pointer
    (*pTest)();         //OR
    pTest();

    (*test)();  //implicit function pointer - name of that function 
    test();     //regular function call

    return 0;
}
