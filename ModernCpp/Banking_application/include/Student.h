#pragma once
#include "Account.h"

class Student:public Account {
    float m_minimumBalance;
public:
    Student(const std::string& name, float balance, float minBal);
    ~Student();

    void withdraw(float amount) override;
    float getMinimumBalance()const;
};