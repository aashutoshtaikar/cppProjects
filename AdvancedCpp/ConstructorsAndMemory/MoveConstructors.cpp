#include<iostream>
#include<memory.h>
#include<vector>
using namespace std;

/*
C++98:
    Lvalue = left ; Rvalue = Right
C++11:
    Lvalue = anything you can take the address of
 */

class Test{
private:
    static const int SIZE = 100;    //no of ints in our buffer
    int *_pBuffer{nullptr};

public:
    Test(){
        _pBuffer = new int[SIZE];
        memset(_pBuffer, 0 , sizeof(int)*SIZE);
    }

    Test(int i){
        cout << "parameterized constructor" << endl;
        _pBuffer = new int[SIZE]{};

        for(int i = 0 ; i < SIZE; i++){
            _pBuffer[i] = 7*i;
        }
    }

    Test(const Test &other){                //copy constructor always has a const Lvalue reference parameter to it
        cout << "copy constructor" << endl;
        _pBuffer = new int[SIZE]{};

        memcpy(_pBuffer, other._pBuffer, sizeof(int)*SIZE);
        //copy constructor can call an assignment operator but to keep seperate we can do=>
    }

    //very efficient than the copy constructor
    Test(Test &&other){
        cout << "move constructor" << endl; //can have a check if this != other
        _pBuffer = other._pBuffer;  //the destructor of other will de-allocate the buffer which we have stolen, which we dont want to happen
        other._pBuffer = nullptr;   //thus this is necessary, also safe to call delete on nullptr. 
        //we stole resources that the Rvalue actually owns and then we are setting them to null in the Rvalue obj, so that it cannot deallocate itself 
    }

    Test &operator=(const Test &other){
        _pBuffer = new int[SIZE]{};

        memcpy(_pBuffer, other._pBuffer, sizeof(int)*SIZE); //avoid memory overruns / underruns 
        
        return *this;
    }
    
    friend ostream &operator<<(ostream &out, const Test &test){
        return out;
    }

    ~Test(){
        cout << "freeing memory" << endl;
        delete [] _pBuffer;
    }

};

Test getTest(){        //copies the obj into temporary return value
    return Test();  //creates a default constructor
}                   //when function return objects they have to copy those objects, thus runs copy constructor
                    

int main(){
    
    vector<Test> vec;
    vec.push_back(Test());

    return 0;
}