/* Perfect forwarding using std::forward and member template for handling rvalues and lvalues for arguments
    
    1. Member template for handling all the perfect forwarding cases for combinations of both arguments
    2. Reference collapsing occurs in constructor if Lvalue passed, arg becomes T1& name ; if Rvalue passed, arg becomes T1&& name
        This will happen only if the defined function template accepts arguments as Rvalue references
    3. std::move will always move/ convert to rvalues, which is not desirable always
    4. std::forward ensures that the typename is preserved 
*/
#include <iostream>
#include <string>
#include "Integer.h"

class Employee
{
private:
    std::string m_name;
    Integer m_id;    

public:
    template<typename T1, typename T2>
    Employee(T1&& name, T2&& id):
        m_name(std::forward<T1>(name)), 
        m_id(std::forward<T2>(id)){
        std::cout << "Employee(std::string&& name, Integer&& id)\n";
    }

    void display(){
        std::cout << m_name << " " << m_id.get() << "\n";
    }

    ~Employee(){}
};

template<typename T1, typename T2>
static Employee* Create(T1&& a, T2&& b){
    return new Employee(std::forward<T1>(a),std::forward<T2>(b));
}

// class tests_employee_Integer{



// };


int main() {
    // Employee emp{"Ash",Integer{100}};

    // std::string name = "Ash";
    // Employee emp{name,100}; // will invoke copy constructor

    // Integer val{100};
    // Employee emp3{"Ash", val};
        

    
    // auto emp = Create("Ash",Integer{100});
    
    return 0;
}