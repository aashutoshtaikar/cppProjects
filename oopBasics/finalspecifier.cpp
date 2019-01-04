#include <iostream> 
using namespace std; 

/* final specifier: doesnt allow derived class to override the base class’ virtual function. */

class Base 
{ 
public: 
    virtual void myfun() final 
    { 
        cout << "myfun() in Base"; 
    } 
}; 
class Derived : public Base 
{ 
    void myfun()                        //<-- error
    { 
        cout << "myfun() in Derived\n"; 
    } 
}; 

class OtherBase final 
{ 
}; 
  
class OtherDerived : public OtherBase //<-- error
{ 
}; 
  

int main() 
{ 
    Derived d; 
    Base &b = d; 
    b.myfun(); 
    return 0; 
} 