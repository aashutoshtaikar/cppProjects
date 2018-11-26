#include<iostream>
using namespace std;

class Sally {
public:
	Sally();				
	Sally(int);
	Sally operator+(Sally); //operatorKeyword<operatorToOverload>
	int num;
};

Sally::Sally() {

}

Sally::Sally(int a) {
	num = a;
}

Sally Sally::operator+(Sally AnotherSallyobj) { //return type class::operatorKeyword<operatorToOverload>(Sally AnotherSallyobj)
	Sally brandNew;								//uses constructor overloading as no parameter of int is passed
	brandNew.num = num + AnotherSallyobj.num;
	return brandNew;
}