#include<iostream>
using namespace std;

/*If we want to define a different implementation for a template when a specific type is passed as template 
parameter, we can declare a class specialization of that template.*/

template<class TestDType>
class Spunky {
public:
	Spunky(TestDType a) {
		cout << a << " is not a character"<< endl;
	}
};

template<>
class Spunky<char> {
public:
	Spunky(char a) {
		cout << a << " is a charachter" << endl;
	}
};

template<>
class Spunky<string> {
public:
	Spunky(string a) {
		cout << a << " is a string" << endl;
	}
};


int main(){
	Spunky<int> obj1(2.72);
	Spunky<double> obj2(2.72);
	Spunky<char> obj3('2.72');
	Spunky<string> obj4("2.72");
	return 0;
}


