#include<iostream>

using namespace std;

////catching exceptions in the right order

void goesWrong(){
    bool error1Detected = false;
    bool error2Detected = true;

    if(error1Detected){
        throw bad_alloc();
    }

    if(error2Detected){
        throw exception();
    }
}

int main(){
    ////by polymorphism -> we can use a subclass whereever the parent class is accepted.
    ////while listing the catch blocks it is important to list the subclass(bad_alloc) first and then the parent class(exception).
    try{
        goesWrong();
    }
    catch(bad_alloc &e){
        cout << "Catching bad_alloc: "<< e.what() <<endl;
    }
    catch(exception &e){
        cout << "Catching exception: " << e.what() << endl;
    }

    return 0;
}