/*  future of the child (waits)depends on the promise of the parent
    Promise from the parent has to be kept
    If the parent breaks promise (cannot set_value on promise) exception occurs
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
    try{
        n = f.get();        //exception if promise broken: std::future_errc::broken_promise
    }
    catch(std::future_error& e){
        std::cout << e.what();
        return 0;
    }
    return factorial(n); 
}

//random number wrapper function
int random_number(int seed, int zero_to_range){
    std::cout << "parent generating a random value for child...\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    
    srand(seed);
    return rand()%zero_to_range;
}


int main() {
    int x;
    std::promise<int> promise_parent;
    std::future<int> future_child = promise_parent.get_future();
    std::future<int> future_parent = std::async(std::launch::async, runFactorial, std::ref(future_child)); //need to be a reference to future

    int val_parent = random_number(time(NULL), 10);
    
    promise_parent.~promise(); //sending custom exception instead of std::future_errc::broken_promise
    //promise_parent.set_value(val_parent); //intentionally breaking the promise

    x = future_parent.get();
    if(x!=0) std::cout << x;
   
    return 0;
}