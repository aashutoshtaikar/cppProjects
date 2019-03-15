#include<iostream>
#include"Toy.h"

using namespace std;

class ToyFactory {
public:
	static Toy* createToy(int type) {
		Toy *toy = NULL;

		switch (type)
		{
		case 1: 
			toy = new Cars;
			break;				//if you delete this line and compile make sure to save the client.cpp otherwise the VS compiler will not compile this saved version of this file
		case 2 : 
			toy = new Bike;
			break;
		case 3:
			toy = new Plane;
			break;
		default:
			cout << "invalid toy, please re-enter type" << endl;
			return NULL;
		}
		toy->prepareParts();
		toy->combineParts();
		toy->assembleParts();
		toy->applyLabel();
		return toy;
	}
	
};