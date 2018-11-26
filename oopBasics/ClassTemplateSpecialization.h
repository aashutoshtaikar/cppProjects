#pragma once
#include<iostream>
//#include<string>
using namespace std;

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


