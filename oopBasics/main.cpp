#include<iostream>
#include<string>
#include<fstream>
#include<ostream>
#include"Deconstructors.h"		// constrcutors, destructors, const function ; a const obj can only call a const function 
#include"MemberInitializers.h"	// Class Car1
#include"Birthday.h"
#include"People.h"
#include"Recursion.h"
#include"Friendexample.h"
#include"OperatorOverloading.h"
#include"Inheritance.h"
#include"Polymorphism.h"			//Polymorphism part1
#include"VirtualfunctionsEtc.h"		//Polymorphism part2
#include"functionTemplates.h"
#include"ClassTemplates.h"
#include"ClassTemplateSpecialization.h"
using namespace std;

//function prototypes
void Deconstructor();
void MemberInits();
void Composition(); //Class Birthday and Class People
void Recur();
void FriendfuncEx();
void thisEx();
void OpOverEx();
void PolymorphismEx();
void functionTemplatesEx();
void classTemplatesEx();
void ClassTemplateSpecializationEx();

template<class T>
T get(std::istream& is) {
	T result;
	is >> result;
	return result;
}

void main() {
	
	PolymorphismEx();
	system("pause");
}

void InheritanceEx() {
	Mother mom;
	mom.sayName();
	//mom.protectedv = 1; // protected variables cannot be accessed directly from an object; 
	//they need to be accessed via a member function of its class or derived class
	Daughter tina;
	tina.DoSomething();
	//tina.protectedv = 1; //
}

void Recur() {
	RecursionExamples Someobj;
	cout<< Someobj.factorialFind(3);
	cout << Someobj.powerOf(3, 2);
}

void Deconstructor() {
	//constructor and destructor example------------------------------
	Car bmw;			//regular object
	bmw.print();        //regular function

	/*	constant object : remains constant throughout the program, cannot be changed or modified
						  const object can only call const function
	*/
	const Car constobj;	//const object
	//constobj.print(); //throws error as print is not a const function
	constobj.print2();	//const function
}

void MemberInits() {
	Car1 bmw(3, 87); //assigns 3 to a regular variable and 87 to a const variable
	bmw.print();	//
}

void Composition() {
	Birthday birthobj(12,11,1993);

	People Ash("Ash", birthobj);
	Ash.PrintInfo();
}

void FriendfuncEx() {
	Car3 someobj;
	Car3sfriend(someobj);
}

void thisEx() {
	Hannah ho(23);
	ho.printCrap();
}

void OpOverEx() {
	Sally a(34);	//a sally obj has num=34
	Sally b(21);	//b sally obj has num=21
	Sally c;

	c = a + b;
	cout << c.num << endl;
}

void PolymorphismEx() {
	Ninja nj;
	Monster mon;
	Enemy *enemy1 = &nj;
	Enemy *enemy2 = &mon;

	enemy1->setAttackPower(28);
	enemy2->setAttackPower(99);

	nj.attack();
	mon.attack();
}

void VirtualFunctionsEtcEx() {
	NinjaX nj;
	MonsterX mon;
	EnemyX *enemy1 = &nj;
	EnemyX *enemy2 = &mon;

	enemy1->setAttackPower(28);
	enemy2->setAttackPower(99);

	enemy1->attack();			//Use of virtual function(it is a template in the base class)
	enemy2->attack();
}

void functionTemplatesEx() {

	// function template with 1 parameter 
	int x = 7, y = 56.5, z;
	cout << addCrap(x, y) << endl;

	// function templates with multiple parameters
	int a = 89;
	double b = 56.78;
	cout << smaller(a, b) << endl;
}

void classTemplatesEx() {
	Bucky <int> bo(258, 105);
	cout << bo.bigger();
}

void ClassTemplateSpecializationEx() {
	Spunky<int> obj1(2.72);
	Spunky<double> obj2(2.72);
	Spunky<char> obj3('2.72');
	Spunky<string> obj4("2.72");
}