#ifndef _HEADER_H 
#include "Header.h"
#endif

void mightGoWrong(){
    bool error1 = false;
    bool error2 = true;
    if(error1){
        throw "something went wrong";
    }
    if(error2){
        throw string("something else went wrong");
    }

}

void usesMightGoWrong(){
    mightGoWrong();
}


void exceptnRunMain(){
    try{
        usesMightGoWrong();
    }
    catch(int e){
        cout<<"Error Code:" << e <<endl;
    }
    catch(char const* e){
        cout<<"Error Code:" << e <<endl;
    }
    catch(string &e){ //catch by referrence is recommended for string object
        cout<<"Error Code:" << e <<endl;
    }
    cout<<"still running"<<endl;
    
}

//memory allocation for a constructor using exceptions
class ConGoWrong{
public:
    ConGoWrong(){
        char *pMemory = new char[99999999999999];
       delete[] pMemory; 
    }
};

void x1Main(){
    try{
        ConGoWrong wrong;
    }                       //bad_alloc is derived from the exceptions base class
    catch(bad_alloc &e){    //bad_alloc is a class, has a method what
        cout << "Caught exception: "<< e.what() <<endl;
    }
    catch(bad_cast &e){
        cout<< "Caught exception: "<< e.what() <<endl;
    }

    cout << "still running"<<endl;
}

////custom exception classes-------------------------
class MyException:public exception{
public:
    virtual const char* what() const throw(){ //overwriting the what method
    //const throw - what() cannot throw an exception - optimizing the code by using less vars for throw 
        return "Something bad happened";
    }


};

class Test{
public:
    void goesWrong(){
        throw MyException();
    }
};

void x2Main(){
    Test test;
    try{
        test.goesWrong();
    }
    catch(MyException &e){
        cout << e.what() << endl;
    }
}

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

void x3Main(){
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

}