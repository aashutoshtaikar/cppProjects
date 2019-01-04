#include<iostream>
#include<fstream>
using namespace std;
//function templates || other alternative function overloading

template <class xType>							//1 parameter
xType addCrap(xType a, xType b) {	//returns the <xType>
	return a + b;
}

template <class xType,class yType>		//multiple parameters for multiple <datatypes>
yType smaller(xType a, yType b) {		//return type is <yType> . i.e returns value as per the datatype of 2nd arg passed
	return (a < b ? a : b);					  
}

template<class T>
T getVar(istream& is) {
	T result;
	is >> result;
	return result;
}

int main() {

	// function template with 1 parameter 
	int x = 7, y = 56.5, z;
	cout << addCrap(x, y) << endl;

	// function templates with multiple parameters
	int a = 89;
	double b = 56.78;
	cout << smaller(a, b) << endl;

	return 0;
}


