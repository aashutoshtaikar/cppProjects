#include "Transaction.h"
#include <iostream>
#include "Student.h" // not a good idea from a design perspective to expose a child class here, this is just to demonstrate RTTI using typeid

void Transact(Account *pAccount){
    std::cout << "------Transaction started------" << "\n";
    std::cout << "Initial balance: " << pAccount->getBalance() << "\n";
    pAccount->deposit(100);
    pAccount->accumulateInterest();    
    pAccount->withdraw(170);
    std::cout << "Interest rate: "<< pAccount->getInterestRate() << "\n";
    std::cout << "Final balance: "<< pAccount->getBalance() << "\n";
}

void Transact_typeid(Account *pAccount){
    std::cout << "------Transaction started------" << "\n";
    std::cout << "Initial balance: " << pAccount->getBalance() << "\n";
    pAccount->deposit(100);
    pAccount->accumulateInterest();
    
    //1. demonstration of RTTI By typeid
    if (typeid(*pAccount)==typeid(Student)) {   
        Student* pStudent = static_cast<Student*>(pAccount);
        std::cout << "min balance of Student: " << pStudent->getMinimumBalance() << "\n";
    }
    
    pAccount->withdraw(170);
    std::cout << "Interest rate: "<< pAccount->getInterestRate() << "\n";
    std::cout << "Final balance: "<< pAccount->getBalance() << "\n";
}

void Transact_dynamic_cast(Account *pAccount){
    std::cout << "------Transaction started------" << "\n";
    std::cout << "Initial balance: " << pAccount->getBalance() << "\n";
    pAccount->deposit(100);
    pAccount->accumulateInterest();
    
    //2. demonstration of RTTI By typeid
    Student* pStudent = dynamic_cast<Student*>(pAccount);
    if (pStudent!=nullptr) {   
        std::cout << "min balance of Student: " << pStudent->getMinimumBalance() << "\n";
    }
    
    pAccount->withdraw(170);
    std::cout << "Interest rate: "<< pAccount->getInterestRate() << "\n";
    std::cout << "Final balance: "<< pAccount->getBalance() << "\n";
}