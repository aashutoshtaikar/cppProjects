#include<iostream>
#include<string>
using namespace std;

//class Strings {
//	//filter a given element
//	void filter(string x, string ) {
//
//	}
//};

int main() {
	string x = "22.5";
	int a = stoi(x);
	float b = stof(x);
	double c = stod(x);
	cout << "integer" << a << endl;
	cout << "float" << b << endl;
	cout << "double" << c << endl;

	string y = "Test";
	int pos = y.at(1);
	int tmp = y.find('x');
	cout << tmp;

	return 0;
}