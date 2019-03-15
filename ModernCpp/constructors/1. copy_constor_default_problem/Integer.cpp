#include "Integer.h"

Integer::Integer()
{
    m_pInt = new int(0);
}

Integer::Integer(int value)
{
    m_pInt = new int(value);
}

int Integer::getValue()
{
    return *m_pInt;
}

void Integer::setValue(int value)
{
    *m_pInt = value;
}


Integer::~Integer()
{
    delete [] m_pInt;
}