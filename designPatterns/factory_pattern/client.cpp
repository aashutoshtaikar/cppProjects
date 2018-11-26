#include<iostream>
#include"ToyFactory.cpp"

using namespace std;

int main() {
	int type;
	while (1)
	{
		cout << endl << "ENter type or Zero for exit" << endl;
		cin >> type;
		if (!type)
			break;	//ends the program when user enters 0
		Toy *v = ToyFactory::createToy(type);
		//Toy *v;
		//v = ToyFactory::createToy(type);
		if (v) {
			v->showProduct();
			delete v;
		}
	}
	cout << "Exit.." << endl;
	return 0;
}