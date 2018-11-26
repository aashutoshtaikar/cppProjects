#pragma once
#include<iostream>
using namespace std;
//Class templates

template <class MyTyp> //makes a generic datatype Typ
class Bucky {
	MyTyp first, second;
public:
	Bucky(MyTyp a, MyTyp b) {
		first = a;
		second = b;
	}
	MyTyp bigger();
};

template <class MyTyp>
MyTyp Bucky<MyTyp>::bigger() {
	return (first > second?first:second);
}

