#ifndef _HEADER_H
#include"Header.h"
#endif

class Test{
private:
    int iD;
    string namE;

public:
    Test():iD(0),namE(""){}

    Test(int id,string name):iD(id),namE(name){}

    //copy constructor overloading
    Test(const Test *other){
        cout << "copy constructor running" << endl;
        iD = other->iD;
        namE = other->namE;
        //this = other;    //use of assignment operator inside the objects copy constructor
    }

    void print(){
        cout << iD << ":" << namE << endl; 
    }

    /* rule of 3 = if a copy constructor/assignment operator/destructor is defined we must define the other 2. 
    *  In this case destructor is not defined as this is just an example and we are not managing any resource/pointer in the object
    */

    const Test *operator=(const Test *other){   //change
        cout << "Assignment running" << endl;
        iD = other->iD;                         //change
        return this;                            //change
    }
};



void opOvPointers(){
    Test* test1 = new Test(10,"Mike");
    test1->print();

    Test* test2 = new Test(20,"Bob");
    test2 = test1;
    test2->print();

    Test *test5= new Test(30,"Tom");
    Test *test6=new Test();
    test6->operator=(test5);            //change
    test6->print();

    delete test1;
    delete test2;
    delete test5;
    delete test6;
}

int main(){
    /* Overloading the assignment operator
    While assigning(=) one object(test1) to another(test2) a shallow copy of an object is assigned to another object
    However sometimes we might want the name copied but not the id and vice versa
    If there is a pointer defined in the class, shallow copy will only copy the reference and would point to the same address pointed to by the test1 object 
     */

    opOvPointers();

    return 0;
}