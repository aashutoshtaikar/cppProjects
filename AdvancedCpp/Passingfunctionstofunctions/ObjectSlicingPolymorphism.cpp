#include <iostream>
using namespace std;

class Parent{
private:
 int one;
public:
    Parent():one(0){}
    //copy constructor
    Parent(const Parent &other){
        cout << "copy parent" << endl;
    }
    
    virtual void print(){
        cout << "parent" << endl;
    }
};

class Child:public Parent{  //have to have a constructor
private:
    int two;
public:
    Child():two(0){}

    void print(){
        cout << "child" << endl;
    }
};

int main(){
    Child c1;
    Parent &p1 = c1;
    p1.print();

    Parent p2 = Child();    //copy init invoked implicit copy constructor
    p2.print();

    return 0;
}
