#include<iostream>
using namespace std;
// member : Anything in a class is a member of that class
/* member initializers : member syntax
const variables need to be initialized using Member Initializers ONLY

Member Initializers are used to the constructor that takes 2 values and put them in regVar and constVar
*/

class Car1
{
public:
	Car1(int a, int b) ;
	void print();

	~Car1();
	
protected:
private:
	int regVar;
	const int constVar;
};



//Constructor with Member Initializers; setting the constructor that takes 2 values and put them in regVar and constVar
Car1::Car1(int a, int b) : regVar(a), constVar(b)
{
	cout << "Constructor" << endl;
}

void Car1::print() {
	cout << "regular Var" << regVar << endl << "const Var" << constVar << endl;
}

Car1::~Car1()
{
	cout << "Deconstrcutor" << endl;
}



