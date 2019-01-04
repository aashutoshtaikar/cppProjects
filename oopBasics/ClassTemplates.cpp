#include<iostream>
using namespace std;


/* Class templates:
We also have the possibility to write class templates, so that a class can have members that use template 
parameters as types. For example: */

template <class MyTyp> //makes a generic datatype Typ
class Bucky {
	MyTyp first, second;
public:
	Bucky(MyTyp a, MyTyp b) {	//class constructor that use template parameters as types
		first = a;
		second = b;
	}
	MyTyp bigger();
};

template <class MyTyp>
MyTyp Bucky<MyTyp>::bigger() {				//class that 
	return (first > second?first:second);
}


int main() {
	Bucky <int> bo(258, 105);
	cout << bo.bigger();

	return 0;
}