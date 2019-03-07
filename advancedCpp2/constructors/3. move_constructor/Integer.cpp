#include <iostream>
#include "Integer.h"

Integer::Integer()
{
    std::cout << "Integer()\n";
    m_pInt = new int(0);
}

Integer::Integer(int value)
{
    std::cout << "Integer(int)\n";
    m_pInt = new int(value);
}

Integer::Integer(const Integer& obj){
    std::cout << "Integer(Integer&)\n";
    m_pInt = new int(*obj.m_pInt); //get the value from the pointer -- deep copy
}

Integer::Integer(Integer&& obj){
    std::cout << "Integer(Integer&&)\n";
    m_pInt = obj.m_pInt;
    obj.m_pInt = nullptr;
}

int Integer::getValue ()const
{
    return *m_pInt;
}

void Integer::setValue(int value)
{
    *m_pInt = value;
}


Integer::~Integer()
{
    std::cout << "~Integer()\n";
    delete [] m_pInt;
}