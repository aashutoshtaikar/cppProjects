#pragma once 
#include <iostream>
class Integer
{
private:
    int* m_pInt;
public:
    Integer():m_pInt{}{
        std::cout << "Integer()\n";
    }

    Integer(int val):m_pInt(new int(val)){
        std::cout << "Integer(int)\n";
    }

    Integer(const Integer& other){
        m_pInt = new int(other.get());
        std::cout << "Integer(const Integer&)\n";

    }

    Integer& operator=(const Integer& other){
        if (m_pInt) { 
            std::cout << "deleting" << m_pInt << "\n";
            delete[] m_pInt;
            m_pInt = nullptr;
        }
        m_pInt = new int(other.get());
        std::cout << "Integer& operator=(const Integer&)\n";
        std::cout << "new addr held:" << m_pInt << "\n";
        return *this;
    }

    Integer(Integer&& other){
        m_pInt = other.m_pInt;
        other.m_pInt = nullptr;
        std::cout << "Integer(Integer&&)\n";
    }

    Integer& operator=(Integer&& other){
        if(m_pInt) delete[] m_pInt;
        m_pInt = other.m_pInt;
        std::cout << "Integer& operator=(Integer&&)\n";
        return *this;
    }

    int get()const{ return *m_pInt; }
    int set(int val){ m_pInt = new int(val); }

    ~Integer(){
        std::cout << "~Integer()\n";
        if(m_pInt) delete[] m_pInt;
    }
};

