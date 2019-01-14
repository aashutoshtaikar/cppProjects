#include<iostream>
using namespace std;

class Parent{
public:
    virtual void speak(){
        cout << "parent speaking " << endl;
    }
};

class Brother: public Parent{

};

class Sister:public Parent{

};

int main(){
    Parent parent;
    Brother brother;
    Sister sister;

    Parent *ppb = &brother;  //polymorphism

    Sister *pbb = reinterpret_cast<Sister *>(ppb);  //casting sister to (parent pointer) ref to brother
    //even less checking than the static cast, but best to avoid it -- does a binary cast of one pointer type to another
    //one type to a completely diff type -- may use reinterpret_cast
    // this works her but it doesnt make sense
    
    if(pbb ==nullptr){
        cout << "Invalid cast" << endl;
    }
    else{
        cout << pbb << endl;
    }
    


    return 0;
}