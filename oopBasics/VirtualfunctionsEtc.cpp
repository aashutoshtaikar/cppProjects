#pragma once
#include<iostream>
using namespace std;

//AN abstract class is like an interface or template which has just the pure virtual functions and the other classes derived must contain their version this function.

class EnemyX //NOT an abstract class(as it does not contain "JUST the pure virtual functions" it has other functions declared)
{
protected:
	int attackPower;
public:
	virtual void attack() = 0; //pure virtual function(No body in base class, but other derived classes NEED to have their version of this function)
	//virtual void attack() {}; // not a pure virtual function (other derived class need not have their own version of this function and it will default to execute the function contained in the base class)
	void setAttackPower(int x) {
		attackPower = x;
	}
};


class NinjaX :public EnemyX {
public:
	void attack() {
		cout << "I am a ninja, ninja chop -" << attackPower << endl;
	}
};

class MonsterX :public EnemyX {
public:
	void attack() {
		cout << "I am a monster -" << attackPower << endl;
	}
};

int main() {
	NinjaX nj;
	MonsterX mon;
	EnemyX *enemy1 = &nj;
	EnemyX *enemy2 = &mon;

	enemy1->setAttackPower(28);
	enemy2->setAttackPower(99);

	enemy1->attack();			//Use of virtual function(it is a template in the base class)
	enemy2->attack();

	return 0;
}
