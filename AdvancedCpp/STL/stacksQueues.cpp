#ifndef _HEADER_H 
#include "Header.h"
#endif

class Test{
private:
    string namE;

public:
    Test(string name):namE(name){
    }

    ~Test(){
        //cout << "Object Destroyed" <<endl;
    }

    void print(){
        cout << namE << endl;
    }
}

void stackExample(){
    stack<Test> testStack; //Last-In-First-Out 
    testStack.push(Test("Mike"));   //object gets destroyed as soon as it is pushed in stack
    testStack.push(Test("John"));
    testStack.push(Test("Sue"));
    testStack.push(Test("Micky"));
    testStack.push(Test("Tom"));
    testStack.push(Test("Harry"));

    Test test1 = testStack.top();   //
    test1.print();
    testStack.pop();                //destructs original object
    test1.print();                  //object is still valid

    Test &test2 = testStack.top();
    test2.print();
    testStack.pop();                //destructs the original object
    test2.print();                  //object reference is invalid

    //popping all of the stack while its size is > 0
    while(testStack.size()>0){
        Test &test = testStack.top();
        test.print();
        testStack.pop();
    }

    cout << endl;
}

void queueExample(){
    queue<Test> testQueue;          //First-In-First-Out FIFO >---->
    testQueue.push(Test("Mike"));   //object gets destroyed as soon as it is pushed in stack
    testQueue.push(Test("John"));
    testQueue.push(Test("Sue"));
    testQueue.push(Test("Micky"));
    testQueue.push(Test("Tom"));
    testQueue.push(Test("Harry"));

    Test test1 = testQueue.front();   //
    test1.print();
    testQueue.pop();                //destructs original object
    test1.print();                  //object is still valid

    Test &test2 = testQueue.front();
    test2.print();
    testQueue.pop();                //destructs the original object
    test2.print();                  //object reference is invalid

    //popping all of the stack while its size is > 0
    while(testQueue.size()>0){
        Test &test = testQueue.front();
        test.print();
        testQueue.pop();
    }

    cout << endl;
}

int main(){
    stackExample();
    queueExample();
    return 0;
}