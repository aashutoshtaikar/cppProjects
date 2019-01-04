#include <iostream>
using namespace std;

class Parent{
private:
 int one;
public:
    Parent():one(0){ cout << "cons parent" << endl;}
    //copy constructor
    Parent(const Parent &other){
        one = other.one;
        cout << "copy parent" << endl;
    }
    
    virtual void print(){
        cout << "printing parent" << endl;
    }
};

class Child:public Parent{  //have to have a constructor
private:
    int two;
public:
    Child():two(0){cout << "cons child" << endl;}

    void print(){
        cout << "printing child" << endl;
    }
};

int main(){
    cout << "-----Object not sliced-----" << endl;
    cout << "-----if passed to a reference-----" << endl;
    Child c1;
    Parent &p1 = c1;
    p1.print();
    
    cout << "------OR-------" << endl;
    cout << "-----if passed to a pointer-----" << endl;

    Parent *p3 = new Child();
    p3->print();
    
    cout << "-----Object slicing----" << endl;
    
    Parent p2 = Child();    //copy init invoked implicit copy constructor
    p2.print();

    return 0;
}
