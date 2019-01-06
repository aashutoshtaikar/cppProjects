#include<iostream>

using namespace std;

//memory allocation for a constructor using exceptions
class ConGoWrong{
public:
    ConGoWrong(){
        char *pMemory = new char[99999999999999];
       delete[] pMemory; 
    }
};

int main(){
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

    return 0;
}