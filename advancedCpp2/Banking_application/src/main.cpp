#include <iostream>
#include <typeinfo>
#include "Account.h"
#include "Savings.h"
#include "Checking.h"
#include "Transaction.h"
#include "Student.h"

void test_Account(){
    Account acc("Bob",1000);
    std::cout << "Initial balance:" << acc.getBalance() << "\n";
    acc.deposit(200);
    acc.withdraw(380);
    std::cout << "Balance: " << acc.getBalance() << "\n";
}

void test_Savings(){
    Savings acc("Bob",50,0.04f);
    acc.deposit(200);
    acc.withdraw(380);
}

void test_Checking(){
    Checking acc("Bob",50);
    acc.deposit(200);
    acc.withdraw(380);
}

void test_Transaction(){
    Savings acc("Bob",100,0.05f);
    Transact(&acc);
}

void test_upcast(){
    Checking ch("Bob",100);
    Account* pAccount = &ch;    //upcast child class ptr to base class ptr

    Checking* pChecking = static_cast<Checking*>(pAccount); //downcast Base class ptr to Child class pointer (requires typecast)
}

void test_RTTI(){
    int i{};
    float f{};
    double d{};
    char c{};
    std::string s{};
    const std::type_info& ti = typeid(i);
    std::cout << ti.name() << "\n";

}


void test_Account_RTTI(){
    Checking ch("Bob",100);
    Account* pAccount = &ch;    //upcast child class ptr to base class ptr

    const std::type_info& ti = typeid(*pAccount);
    if(ti == typeid(Checking))
        std::cout << ti.name() << "\n";
}

void test_Student_RTTI(){
    Student st("Bob",100,50);
    Transact(&st);
    
    Checking ch("Tom",100);
    Transact(&ch);
}


int main()
{
    test_Student_RTTI();

    return 0;
}
