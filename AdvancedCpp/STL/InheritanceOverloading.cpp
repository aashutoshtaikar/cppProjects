#include <iostream> 
using namespace std; 
// function overloading does not work with Inheritance in c++, c#
//	it however works in java
// constructor of base class cannot be overloaded by derived class as it requires to have the same name
class Base { 
public:
	int num;
	Base():num(0){} 

	Base(int i):num(i){
		cout << "default constructor" << endl;
	}

	int f(int i) 
	{ 
		cout << "f(int): "; 
		return i+3; 
	} 
}; 

class Derived : public Base { 
public: 
	double num;
	Derived():Base(0){}

	Derived(double i):num(i){}

	// Derived(int i):Base(i){
	// 	cout<<"derived constructor after calling default constructor" << endl;
	// }

	Derived(int i):num(i){
		cout<<"derived constructor only" << endl;
	}
	
	Derived(Derived *derobj,const Base *basobj) {
		derobj->num=basobj->num;  
		cout<<"copied base obj "<< basobj->num <<" to derived object" << derobj->num << endl;
	}

	double f(double d) { 
		cout << "f(double): "; 
		return d+3.3; 
	} 
}; 

int main() { 
	cout << "-----new Base of type Base*-----" << endl;
	Base* baseBase = new Base; 
	cout << baseBase->f(3) << '\n'; 
	cout << baseBase->f(3.3) << '\n'; 
	delete baseBase; 

/* //throws error - invalid conversion from ‘Base*’ to ‘Derived*
	Derived* derivedBase = new Base; 
	cout << derivedBase->f(3) << '\n'; 
	cout << derivedBase->f(3.3) << '\n'; 
	delete derivedBase; */

	cout << "-----new Derived of type Base*-----" << endl;
	Base* baseDerived = new Derived(1); 
	cout << baseDerived->f(3) << '\n'; 
	cout << baseDerived->f(3.3) << '\n'; 
	delete baseDerived;

	cout << "-----new Derived of type Derived*-----" << endl;
	Derived* derived = new Derived(1); 
	cout << derived->f(3) << '\n'; 
	cout << derived->f(3.3) << '\n'; 
	delete derived;

	cout << "---copying base obj to derived obj-----" << endl;
	Base* newBase = new Base(1); 
	Base* foo = new Derived(derived,newBase);
	cout<< "Derived:" << derived->num << "base:" << baseBase->num << endl;
	
	return 0; 
}