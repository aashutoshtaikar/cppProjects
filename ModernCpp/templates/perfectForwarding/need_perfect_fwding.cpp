#include <iostream>
#include <string>
#include "Integer.h"

class Employee
{
private:
    std::string m_name;
    Integer m_id;    
public:
    Employee(const std::string& name, const Integer& id):
        m_name(name), 
        m_id(id){
            std::cout << "Employee(const std::string& name, const Integer& id)\n"; 
    }

    Employee(std::string&& name, Integer&& id):
        m_name(name), 
        m_id(std::move(id)){    
        std::cout << "Employee(std::string&& name, Integer&& id)\n";
    }
    //id has a name, thus considered like an lvalue and Integer(const Integer&) is invoked, std::move converts it into rvalue
    //However, there is another problem as we never know how the Employee object will be created
    //The solution is to use member_template, we need a mechanism to pass id as an rvalue irrespective of the Employee object creation
    ~Employee(){}
};



int main() {
    // Employee emp{"Ash",100}; // will invoke move constructor because of using std::move

    std::string name = "Ash";
    Employee emp{name,100}; // will invoke copy constructor even if 100 is rvalue

    Integer val{100};
    Employee emp3{"Ash", val};

    return 0;
}