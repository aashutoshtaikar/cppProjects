#include<iostream>
using namespace std;

class Parent{
    int x;
    string text;

public:
    //in C++98 no constructor delegators make init method which all functions can call
    Parent(); //= default; //no longer can be default constructor as we do constructor initialization
    Parent(string text);

};

    Parent::Parent():Parent("hello"){   
        x = 5;
        cout << "no parameter parent constructor" << endl;
    }

    Parent::Parent(string text){
        x = 5;
        this->text = text;
        cout << "string para parent constructor" << endl;
        //should not create a recursion for eg. calling the default constructor with no args
    }

class Child:public Parent{
public:
    Child() = default;
    // Child():Parent("hello"){}

};

int main(){
    Parent par;
    cout << "------------" << endl;
    Parent parent("hello");
        cout << "------------" << endl;
    Child child;


    return 0;
}