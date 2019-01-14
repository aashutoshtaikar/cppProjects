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

    //casting in c
    float value = 3.23;

    cout << (int)value << endl;
    cout << int(value) << endl;
    cout << static_cast<int>(value) << endl;

    Parent *ppb = &brother;  //polymorphism

    //Brother *pbb = &parent; //doesnt work

    //Brother *pb = static_cast<Brother *>(&parent);   workaround but unsafe as the brother class may not have parent functions
    //static cast is compile time thing, no runtime check
    
    // Brother *pbb = static_cast<Brother *>(ppb);
    // cout << pbb << endl;

    //dynamic cast detects at runtime

    Brother *pbb = dynamic_cast<Brother *>(ppb);
    cout << pbb << endl;

    if(pbb ==nullptr){
        cout << "Invalid cast" << endl;
    }
    else{
        cout << pbb << endl;
    }
    


    return 0;
}