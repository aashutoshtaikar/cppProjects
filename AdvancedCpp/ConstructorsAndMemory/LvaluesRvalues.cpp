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

    Test(const Test &other){
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

    int value1 = 7;
    
    int *pValue1 = &value1;
    //int *pValue2 = &7; //cannot work as &7 is not an Lvalue, it is an Rvalue(temporary value)

    Test *pTest1 = &test1;
    //Test *pTest2 = &getTest(); //&getTest() return value is an RValue

    int *pValue3 = &++value1;
    cout << *pValue3 << endl;

    // int *pValue4 = &value1++; 

    //int s = &(7 + value1); //7 is an Rvalue, thus cannot take the address

    //Rvalues are the return values of functions as they are temporary and doesnt have address



    return 0;
}