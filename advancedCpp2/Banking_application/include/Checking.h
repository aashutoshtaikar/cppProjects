#pragma once
#include "Account.h"
#include<string>

class Checking: public Account {

public:
    using Account::Account; //(c++11) inherits parameterized constructor of the base class instead of defining same constructor
    //will cause all the base class constructors to be inherited in this class

    // Checking(const std::string& name, float balance);
    
    ~Checking();

    void withdraw(float amount) override;

};