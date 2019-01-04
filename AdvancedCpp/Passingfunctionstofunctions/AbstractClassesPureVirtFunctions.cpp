#include <iostream>
using namespace std;


//abstract class  - class with only pure virtual functions
//pure virtual functions forces the object of derived class to have all the functions

class Animal{               //Abstract class cant run a constructor
public:
    Animal(){cout << "animal constructor" << endl;}
    virtual void run() = 0;
    virtual void speak() = 0;
};

class Dog:public Animal{
public:
    virtual void speak(){
        cout << "   woof!" << endl;
    }
};

class Labrador:public Dog{
public:
    Labrador(){
        cout << " new labrador" << endl;
    }
    virtual void run(){
        cout << "  labrador running" << endl;
    }
};



int main(){
    //Animal x;   //error: object of abstract class not allowed
    //Dog g;      //error: does not have all the functions contained in the abstract base class
    Labrador lab[5];
    



    return 0;
}