#include<iostream>
using namespace std;
/* 
Constructors, Destructors, const function ; a const obj can only call a const function 

Deconstructors: 
Gets called when program ends
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

int main() {
	//constructor and destructor example------------------------------
	Car bmw;			//regular object
	bmw.print();        //regular function

	/*	constant object : remains constant throughout the program, cannot be changed or modified
						  const object can only call const function
	*/
	const Car constobj;	//const object
	//constobj.print(); //throws error as print is not a const function
	constobj.print2();	//const function
	return 0;
}
