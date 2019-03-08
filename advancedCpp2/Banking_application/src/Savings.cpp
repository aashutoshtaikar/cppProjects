#include "Savings.h"

Savings::Savings(const std::string &name, float balance, float rate) : Account(name, balance), m_interestRate(rate){
}

Savings::~Savings(){
}

float Savings::getInterestRate() const{
    return m_interestRate;
}

void Savings::accumulateInterest(){
    m_balance += (m_balance * m_interestRate);
}