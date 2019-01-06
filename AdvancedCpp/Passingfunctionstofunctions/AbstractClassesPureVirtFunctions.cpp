#include <iostream>
using namespace std;

/* 
abstract class  - class with only pure virtual functions
pure virtual functions forces the object of derived class to have all the functions
Besides we can create a pointer array of objects of base class and have objects of sub classes assigned to each pointer of the array. 
*/

class Animal{                   //abstract class (base class)
public:
    Animal(){
        cout << "new Animal" << endl;
    }
    Animal(const Animal &obj){
        cout << " Animal copy constructor" << endl;
    }
    
    virtual void run() = 0;
    virtual void speak() = 0;

    virtual ~Animal(){}
};

class Dog:public Animal{            //incomplete derived class
public:
    virtual void speak(){
        cout << "   woof!" << endl;
    }
};

class Labrador:public Dog{
public:
    Labrador(){
        cout << " new Labrador" << endl;
    }
    //overloading base class copy constructor
    Labrador(const Labrador &other){
        cout << "Labrador copy constructor" << endl;
    }

    virtual void run(){
        cout << "  labrador running" << endl;
    }


};

void test(Animal &a){
    a.run();
}


int main(){
    //Animal x;   //error: object of abstract class not allowed
    //Dog g;      //error: missing some function of abstract class
    Labrador x;
    Labrador ani(x); 
    cout << "--------" << endl;

    Labrador lab;   /* no error as it has implementation for every pure virtual function defined in abstract class. */
    lab.run();
    lab.speak();
    cout << "--------" << endl;

    /* can create(object) array of pointers to Animal super-class and put all kinds of (objects of) subclasses in the array of pointers. */
    Animal *animal[5];
    animal[0] = &lab;
    animal[0]->speak();
    animal[1] = new Labrador();
    animal[1]->run();
    cout << "--------" << endl;

    test(lab);
    
    
    return 0;
}