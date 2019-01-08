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
    //declaring a function pointer to the test function
    void (*pTest)(); //void pointer to a function, no parameters
    
    //assigning function to a function pointer;   pTest = &test();  //() is a function-call-operator so cannot be used for assingment
    pTest = &test;      // defining addr of test //OR
    pTest = test;       // name of the function is pointer to that function
    
    //calling the function using function pointer
    (*pTest)();         //OR
    pTest();

    //undeclared implicit function pointer
    (*test)();  // name of that function is a pointer to that function
    test();     //regular function call

    return 0;
}
