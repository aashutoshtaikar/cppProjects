#include<iostream>
#include<memory.h>
#include<vector>
using namespace std;

/*Rule of 3: if using an assignment operator you need a copy constructor and a destructor
C++98:
    Lvalue = left ; Rvalue = Right
C++11:
    Lvalue = anything you can take the address of
    Rvalue = temp values
 */

class Test{
private:
    static const int SIZE = 100;    //no of ints in our buffer
    int *_pBuffer{ nullptr };

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

    Test(const Test& other){ // Copy constructor - initialise this object from other
        _pBuffer = new int[SIZE]; // _pBuffer is uninitialised - OK to overwrite it
        memcpy(_pBuffer, other._pBuffer, sizeof(int)*SIZE);
    }
 
    Test(Test&& other) { // Move constructor - initialise this object from other and grab other's resources
        _pBuffer = other._pBuffer; // _pBuffer is uninitialised - OK to overwrite it
        other._pBuffer = nullptr; // All your resource are belong to us!
    }
 
    Test& operator=(const Test& other) { // Regular assignment operator
        if (this != &other) {
            delete [] _pBuffer; // Clean up (this)our resources by releasing the allocated memory
            _pBuffer = new int[SIZE]; // _pBuffer no longer points to valid memory - OK to overwrite it
            // Copy data from other._pBuffer
        }
        return *this;
    }
 
    Test& operator=(Test&& other) { // Move assignment operator
        if (this != &other) {
            delete [] _pBuffer; // Clean up (this)our resources by releasing the allocated memory
            _pBuffer = other._pBuffer; // _pBuffer no longer points to valid memory - OK to overwrite it
            other._pBuffer = nullptr; // All your resource are belong to us!
        }
        return *this;
    }
 
    ~Test() { // Destructor
        delete [] _pBuffer;
    }

};

Test getTest(){        //copies the obj into temporary return value
    return Test();  //creates a default constructor
}                   //when function return objects they have to copy those objects, thus runs copy constructor
                    

int main(){
    
    // vector<Test> vec;
    // vec.push_back(Test());

    Test test; 
    test = getTest(); //

    return 0;
}