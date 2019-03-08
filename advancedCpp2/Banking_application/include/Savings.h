#pragma once
#include "Account.h"

class Savings:public Account {
    float m_interestRate;

public:
    //using Account::Account; //cannot do this here as there is an additional arg to Savings Constr
    Savings(const std::string& name, float balance, float rate);
    ~Savings();

    float getInterestRate()const override;
    void accumulateInterest() override;
};