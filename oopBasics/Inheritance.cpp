#include<iostream>
using namespace std;

class Mother //base class
{
public:
	Mother();
	void sayName();
	int publicv;

protected: // anything inside the class has access to this , derived class
	int protectedV;

private: //only this class will have access, derived class cannot access this
	int privatev;
};

Mother::Mother(){}

void Mother::sayName(){}

class Daughter:public Mother //derived class inherits mother class. Will not grab the constructor Mother(). Public because
{
public:
	void DoSomething();
};

void Daughter::DoSomething() {
	publicv = 1;
	protectedV = 2;
	//privatev = 3; //ccannot inherit this
}


int main() {
	Mother mom;
	mom.sayName();
	
	//mom.protectedv = 1; // protected variables cannot be accessed directly from an object; 
	//they need to be accessed via a member function of its class or derived class
	
	Daughter tina;
	tina.DoSomething();
	
	//tina.protectedv = 1; //
	
	return 0;
}