#include<iostream>
using namespace std;

void PrintbyPtr(int *ptr){
	if(ptr!=nullptr) cout << *ptr << endl;
}

void PrintbyRef(int &ptr){
	cout << ptr << endl;
}

int main() {
	int x = 5;
	PrintbyPtr(&x);
	PrintbyRef(x);

	return 0;
}