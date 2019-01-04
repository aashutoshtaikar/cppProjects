
/* 	Static member Var: only one copy of the data is maintained for all objects of the class.
	
	Static member Functions: can be called without creating an object using the scope resolution operator
	
	const member functions:
	Declaring a member function with the const keyword specifies that the function is a "read-only" function that does not modify the object for which it is called.
	A constant member function cannot modify any non-static data members or call any member functions that aren't constant.
*/

//Interface .h file
#include<iostream>
#include<string>
using namespace std;

class Bank {
private:
	string name;
	int accountNumber;
	double balance;

	static int totalAccounts; //cannot initialize static vars here
	static double bankBalance;

public:
	Bank();						//default constructor
	Bank(string, int, double);	//overloaded constructor with args
	~Bank();					//destructor

	//getters/setters
	void setName(string);
	void setAccountNumber(int);
	void setBalance(double);

	string getName() const;
	int getAccountNumber() const;
	double getBalance() const;
	void withdraw(double);
	void deposit(double);
	static void someStaticMethod();
};


//Implementation .cpp file

//initializing static member variables 
int Bank::totalAccounts = 0;
double Bank::bankBalance = 10000;

Bank::Bank() {
	accountNumber = 0;
	balance = 0.0;
	totalAccounts++;	//increments static var by 1
}

Bank::Bank(string newName, int newAccountNumber, double newBalance) {
	name = newName;
	accountNumber = newAccountNumber;
	balance = newBalance;
	totalAccounts++;	//increments static var by 1
	bankBalance += newBalance;	
}

Bank::~Bank() {	
	totalAccounts--;
	bankBalance -= balance;
}

void Bank::someStaticMethod(){
	cout << "printing from static method" << endl;
}

//setters  
void Bank::setName(string newName) {
	name = newName;
}

void Bank::setAccountNumber(int newAccountNumber) {
	accountNumber = newAccountNumber;
}

void Bank::setBalance(double newBalance) {
	bankBalance -= balance;	//<--(this) first subtract that object's balance from the global static var(bankBalance)
	balance = newBalance;	// and then set the newBalance in that object's balance
	bankBalance += balance; //(NOT just this but also)^ add that object's balance to the bankBalance
}

//getters 

string Bank::getName() const {
	return name;
}


int Bank::getAccountNumber() const {
	return accountNumber;
}

double Bank::getBalance() const {
	return balance;
}

void Bank::withdraw(double amt) {
	balance -= amt;
	bankBalance -= balance;
}

void Bank::deposit(double amt) {
	balance += amt;
	bankBalance += balance;
}

int main(){
	Bank::someStaticMethod();
	Bank x;
	x.someStaticMethod();

	return 0;
}