#include<iostream>
#include<memory.h>
using namespace std;

class Test{
private:
    static const int SIZE = 100;
    int *m_pBuffer;

public:
    Test(){
        cout << "default constructor" << endl;
        m_pBuffer = new int[SIZE];
        memset(m_pBuffer, 0 , sizeof(int)*SIZE);
    }

    Test(const Test &other){
        cout << "copy constructor"  << endl;
        memcpy(m_pBuffer,other.m_pBuffer,sizeof(int)*SIZE);
    }

    Test &operator=(const Test &other){
        return *this;
    }

};