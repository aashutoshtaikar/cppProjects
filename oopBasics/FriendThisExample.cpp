#include<iostream>
using namespace std;

class Car3
{
public:
	Car3() { privateVar = 0; }

private:
	int privateVar;

	friend void Car3sfriend(Car3 &c3f); //this function has access to everything as it is a friend of this class
};

void Car3sfriend(Car3 &c3f) {
	c3f.privateVar = 99;
	cout << c3f.privateVar << endl;
}

//this keyword
class Hannah {

public:
	Hannah(int);
	void printCrap();

private:
	int h;
	
};

Hannah::Hannah(int num):h(num){}

void Hannah::printCrap() {
	cout << "h=" << h << endl;
	cout << "this->h =" << this->h << endl;
	cout << "(*this).h =" << (*this).h<< endl;
}

void friendEx(){
	Car3 someobj;
	Car3sfriend(someobj);
}

void thisEx() {
	Hannah ho(23);
	ho.printCrap();
}


int main() {
	cout << " friend member function example---"<< endl;
	friendEx();
	
	cout << " This keyword example---"<< endl;
	thisEx();
	
	return 0;
}
