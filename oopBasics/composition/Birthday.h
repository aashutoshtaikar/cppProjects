#pragma once

#include<iostream>
using namespace std;

//interface
class Birthday
{
public:
	Birthday(int m, int d, int y);
	void printDate();
	
private:
	int month;
	int day;
	int year;
};


//implementation
Birthday::Birthday(int m, int d, int y)
{
	month = m;
	day = d;
	year = y;
}

void Birthday::printDate() {
	cout << month << "/" << day << "/" << year << endl;
}

