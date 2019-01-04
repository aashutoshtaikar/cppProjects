#include<iostream>
#include<string>
#include<list>
#include"People.h"

using namespace std;

void PrintbyPtr(int *ptr){
	if(ptr!=nullptr) cout << *ptr << endl;
}

void PrintbyRef(int &ptr){
	cout << ptr << endl;
}

int main() {
	Birthday birthobj(12,12,9999);

	People Ash("Ash", birthobj);
	Ash.PrintInfo();
	int x = 5;
	PrintbyPtr(&x);
	PrintbyRef(x);

	return 0;
}