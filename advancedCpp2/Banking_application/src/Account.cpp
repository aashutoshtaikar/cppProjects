#include "Account.h"

int Account::m_accNumGenerator = 1000;

Account::Account(const std::string &name, float balance):m_name(name), m_balance(balance)
{
    m_accNo = ++m_accNumGenerator;
}

Account::~Account()
{
}

//getters
const std::string Account::getName() const{
    return m_name;
}

float Account::getBalance() const{
    return m_balance;
}

int Account::getAccountNo() const{
    return m_accNo;
}

//operations
void Account::withdraw(float amount){
    if(m_balance>amount) {
        m_balance -=amount;
    std::cout << amount << " withdrawn. Current balance: " << m_balance << "\n";
    }
    else std::cout << "Insufficient balance" << "\n";
}

void Account::deposit(float amount){
    m_balance += amount;
    std::cout << amount << " deposited. Current balance: " << m_balance << "\n";
}

//will be implmented by child classes 

void Account::accumulateInterest(){
}

float Account::getInterestRate() const 
{
    return 0.0f;
}