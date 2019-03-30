#include <iostream>
#include <functional>
using namespace std;

class Parent{
private:
    int one;
public:
    Parent():one(0){ cout << "constructor parent" << endl;}

    Parent(const Parent &other){        //copy constructor
        one = other.one;
        cout << "copy parent" << endl;
    }
    
    virtual void print(){
        cout << "printing parent" << endl;
    }
};

class Child:public Parent{      //have to have a constructor for new keyword
private:
    int two;
public:
    Child():two(0){cout << "constructor child" << endl;}

    Child(const Child& other){
        two = other.two;
        cout << "copy child\n"; 
    }

    void print(){
        cout << "printing child" << endl;
    }
};

int main(){
    //No object slicing if passed to a reference
    Child c1;
    Parent &p1 = c1;
    p1.print();

    //OR if passed to a pointer
    Parent *p2 = new Child();
    p2->print();
    delete p2;
    
    //Object slicing
    Parent p3 = Child();    //copy init invoked implicit copy constructor
    p3.print();

    
    return 0;
}
