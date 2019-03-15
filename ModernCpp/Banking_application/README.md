# A Simple Banking Application which implements:    
1. An Account base class which can perform given functions   (Base class)  
2. A Savings, Checking, Student class which inherits from Account (Derived classes)  
3. Functions in Main to test each class.  
4. Functions in Main to test upcast, RTTI for the Student class  

### Class Account   
-> Constructor to set name and balance    
##### data  
name            => can be a string/char array,    
account_number  => must be tied to the class not to its objects  
balance         => can be a float/double    

##### functions  
deposit         => balance must increment by that amount  
getbalance      => to display balance  
withdraw        => cannot withdraw more than the balance, balance must decrement by that amount   
accumulateInterest,getInterestRate => should have a default implmentation which gives out error message and these methods must be overridden in the Savings class 

### Class Savings inherits Account   
-> Constructor: Uses Account to set defaults, sets interestRate  
-> data: interestRate  
-> functions: accumulateinterest, getInterestRate   

### Class Checking inherits Account   
-> Constructor: inherits Account constructor  
-> data: nothing of its own  
-> functions: withdraw  

### Class Student inherits Account     
-> Constructor: Uses Account to set defaults, sets minimumBalance  
-> data: mininumBalance  
-> functions: withdraw(cannot withdraw more than minimumBalance)  

### Transaction.h must demonstrates polymorphism 
#### Transact 
-> Accepts Account type pointer,    
#### Transact_typeid
-> Accepts Account type pointer, RTTI using typeid   
#### Transact_dynamic_cast
-> Accepts Account type pointer, RTTI using dynamic_cast  