/* Passing a value from parent to child, not while creating child thread, 
    deffer function run by the child thread, until it gets value from parent's promise
    
    1. Promise is made by the parent to child (that it will set a value in future) 
    2. child's future waits on promise to get future
    3. as soon as the parent sets the value on the promise, the child thread gets the value and runs function 

    future of the child (waits)depends on the promise of the parent
 */
#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>
#include <future>

//recursive factorial function
int factorial(int n){
    if (n==1) {
        return 1; //base case
    }
    else{
        return n * factorial(n-1); 
    }
}

//function for the child thread
int runFactorial(std::future<int>& f){
    int n = 0;
    n = f.get();
    return factorial(n); 
}

//random number wrapper
int random_number(int seed, int zero_to_range){
    srand(seed);
    return rand()%zero_to_range;
}


int main() {
    int x;

    std::promise<int> promise_parent;
    std::future<int> future_child = promise_parent.get_future();
    std::future<int> future_parent = std::async(std::launch::async, runFactorial, std::ref(future_child)); //need to be a reference to future

    std::cout << "parent generating a random value for child...\n";
    int val_parent = random_number(time(NULL), 10);
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    std::cout << "parent generated " << val_parent << ", setting val on the promise\n";

    promise_parent.set_value(val_parent);
    x = future_parent.get();
    std::cout << "value from child thread:"<< val_parent <<"!=" << x << "\n"; 

    return 0;
}