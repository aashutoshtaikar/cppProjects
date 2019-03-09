# A Simple Banking Application to:    
1. Manage Accounts  
2. Customers can perform common operations  
3. Bank can perform admin tasks  
4. Represent account through account class
5. Common implementation for all account types  

### Class Account (Base)  (5)
-> data: name, accno, balance    
-> functions: withdraw, deposit, getbalance, accumulateinterest(N/A), getInterestRate  (1)

### Class Savings inherits Account   
-> Constructor: Uses Account to set defaults, inits interestRate  
-> data: interestRate  
-> functions: accumulateinterest, getInterestRate   (1)

### Class Checking inherits Account   
-> Constructor: inherits Account constructor  
-> data: nothing of its own  
-> functions: withdraw  (1)

### Class Student inherits Account     
-> Constructor: Uses Account to set defaults, inits minimumBalance  
-> data: mininumBalance  
-> functions: withdraw(cannot withdraw less than minimumBalance)  (1)

### Transaction.h  
#### Transact
-> Accepts Account type pointer, demonstrates polymorphism  
#### Transact_typeid
-> Accepts Account type pointer, demonstrates polymorphism, RTTI using typeid   
#### Transact_dynamic_cast
-> Accepts Account type pointer, demonstrates polymorphism, RTTI using dynamic_cast  