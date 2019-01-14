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
    int *_pBuffer;

public:
    Test(){
        cout << "default constructor" << endl;
        // m_pBuffer = new int[SIZE]{}; //C++11
        // m_pBuffer = new int[SIZE](); //C++11
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
        cout << "copy constructor"  << endl;
        _pBuffer = new int[SIZE]{};

        memcpy(_pBuffer, other._pBuffer, sizeof(int)*SIZE);
        //copy constructor can call an assignment operator but to keep seperate we can do=>
    }

    Test &operator=(const Test &other){
        //=>this
        cout << "assignment" << endl;
        _pBuffer = new int[SIZE]{};

        memcpy(_pBuffer, other._pBuffer, sizeof(int)*SIZE); //avoid memory overruns / underruns 
        
        return *this;
    }
    
    friend ostream &operator<<(ostream &out, const Test &test){
        out << "hello from test";
        return out;
    }

    ~Test(){
        cout << "freeing memory" << endl;
        delete [] _pBuffer;
    }

};

Test getTest(){
    return Test();  //creates a default constructor
}                   //when function return objects they have to copy those objects, thus runs copy constructor
                    //copies the obj into temporary return value



int main(){
    Test test1 = getTest();

    
    
    
    //Lvalue ref to an Lvalue
    Test &rTest1 = test1;

    //If we try to bind a Lvalues ref to Rvalue we get error if const is not used 
    const Test &rTest2 = getTest();
    //const Lvalue references can infact bind to Rvalues, Rvalue lifetime gets extended as long as Lvalue ref exist
    //the return obj from getTest() exist as long as Lvalue exist

    Test test2(Test(1)); //Test(1) is an Rvalue as there is no object name thus it is passed to a const Lvalue ref


    return 0;
}