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


int main() {
	Ninja nj;
	Monster mon;
	Enemy *enemy1 = &nj;
	Enemy *enemy2 = &mon;

	enemy1->setAttackPower(28);
	enemy2->setAttackPower(99);

	nj.attack();
	mon.attack();

	return 0;
}