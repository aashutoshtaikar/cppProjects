#include "Checking.h"

// Checking::Checking(const std::string& name, float balance): Account(name,balance){

// }

Checking::~Checking() {

}

void Checking::withdraw(float amount){
    if((m_balance-amount) > 50){
        Account::withdraw(amount); //cannot do withdraw(amount) as it will execute recursive call and will be undersirable
    }
    else 
        std::cout << "Insufficient balance. Balance cannot go below 50. Maximum withdrawable amount:" << m_balance-50 << "\n"; 
}

