#pragma once
#include<iostream>
#include<string>
#include"Birthday.h" //to store birthday object to use in this class
using namespace std;

class People
{
public:
	People(string x, Birthday bo);
	void PrintInfo();
private:
	string name;
	Birthday dateOfBirth;
};

People::People(string x, Birthday bo)
	: name(x), dateOfBirth(bo)
{

}

void People::PrintInfo() {
	cout << name << " was born on ";
	dateOfBirth.printDate();
}
