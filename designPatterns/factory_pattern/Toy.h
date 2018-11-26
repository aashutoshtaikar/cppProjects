#pragma once
#include<iostream>
#include<string>

using namespace std;

class Toy {
protected:
	string name;
	float price;
public:
	virtual void prepareParts() = 0;
	virtual void combineParts() = 0;
	virtual void assembleParts() = 0;
	virtual void applyLabel() = 0;
	virtual void showProduct() = 0;
};

class Cars :public Toy {
	void prepareParts() { cout << "Preparing car parts" << endl; }
	void combineParts(){ cout << "Combining Car Parts" << endl; }
	void assembleParts() { cout << "Assembling Car Parts" << endl; }
	void applyLabel(){ cout << "Applying Car Label" << endl;  name = "car"; price = 10; }
	void showProduct(){ cout << "Name: "<< name << endl << "Price: " << price << endl; }
};

class Bike :public Toy {
	void prepareParts() { cout << "Preparing bike parts" << endl; }
	void combineParts() { cout << "Combining bike Parts" << endl; }
	void assembleParts() { cout << "Assembling bike Parts" << endl; }
	void applyLabel() { cout << "Applying bike Label" << endl;  name = "bike"; price = 5; }
	void showProduct() { cout << "Name: " << name << endl << "Price: " << price << endl; }
};

class Plane :public Toy {
	void prepareParts() { cout << "Preparing Plane parts" << endl; }
	void combineParts() { cout << "Combining Plane Parts" << endl; }
	void assembleParts() { cout << "Assembling Plane Parts" << endl; }
	void applyLabel() { cout << "Applying Plane Label" << endl;  name = "Plane"; price = 50; }
	void showProduct() { cout << "Name: " << name << endl << "Price: " << price << endl; }
};

