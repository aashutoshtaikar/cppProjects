#pragma once
#include <iostream>
#include<string>

class Account
{
private:
    std::string m_name;
    int m_accNo;
    static int m_accNumGenerator;

protected:
    float m_balance;

public:
    Account(const std::string& name, float balance);
    virtual ~Account(); //for polymorphic call to the derived class destructor
    
    //getters
    const std::string getName()const;
    float getBalance()const;
    int getAccountNo()const;

    //operations
    virtual float getInterestRate()const;   //polymorphic for Savings
    virtual void accumulateInterest();      //polymorphic for Savings
    virtual void withdraw(float amount);    //polymorphic for Checking

    void deposit(float amount);
    

};


