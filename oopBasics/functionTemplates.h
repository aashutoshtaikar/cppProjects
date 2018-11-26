#pragma once
#include<iostream>
using namespace std;
//function templates || other alternative function overloading


template <class MyDataType>			//1 parameter
MyDataType addCrap(MyDataType a, MyDataType b) {
	return a + b;
}

template <class First,class Second>		//multiple parameters for multiple datatypes
Second smaller(First a, Second b) {		//returns the Second type of data 
	return (a < b ? a : b);
}




