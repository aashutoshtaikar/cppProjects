#include<iostream>
#include<memory.h>
using namespace std;


/* Allocating memory */

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

    Test &operator=(const Test &other){ //=>this
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
    Test test1 = getTest();         //copying the temporary return value object to test1 object, thus runs a copy constructor
    //test1 = testx //runs assignment
    cout << "------------" << endl;
    cout << test1 << endl;

    return 0;
}