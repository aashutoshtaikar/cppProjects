#include "Student.h"

Student::Student(const std::string& name, float balance, float minBal):Account(name,balance),m_minimumBalance(minBal) {

}

Student::~Student() {

}

void Student::withdraw(float amount) {
    if ((m_balance-amount)>m_minimumBalance) {
        Account::withdraw(amount);
    }
    else 
      std::cout << "Insufficient balance. Balance cannot go below 50. Maximum withdrawable amount:" << m_balance-m_minimumBalance << "\n";
}

float Student::getMinimumBalance()const{
    return m_minimumBalance;
}