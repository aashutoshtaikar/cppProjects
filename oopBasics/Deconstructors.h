#include<iostream>
using namespace std;

/* Deconstructors: Gets called when program ends
No parameters,
never has a return value,
no overloading
*/

class Car
{
public:
	Car();
	~Car();
	void print();
	void print2()const;

protected:
private:
};

void Car::print() {
	cout << "regular function" << endl;
}

void Car::print2()const {
	cout << "const function" << endl;
}

Car::Car()
{
	cout << "Constructor" << endl;
}

Car::~Car()
{
	cout << "Deconstrcutor" << endl;
}


