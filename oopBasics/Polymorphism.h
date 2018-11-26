#pragma once
#include<iostream>
using namespace std;

class Enemy
{
protected:
	int attackPower;
public:
	void setAttackPower(int x) {
		attackPower = x;
	}
};


class Ninja:public Enemy {
public:
	void attack() {
		cout << "I am a ninja, ninja chop -" << attackPower << endl;
	}
};

class Monster:public Enemy {
public:
	void attack() {
		cout << "I am a monster -" << attackPower << endl;
	}
};
