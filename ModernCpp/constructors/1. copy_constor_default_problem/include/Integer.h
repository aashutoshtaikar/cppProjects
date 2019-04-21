#pragma once

class Integer
{
private:
    int* m_pInt;
public:
    Integer();
    Integer(int value);
    int getValue();
    void setValue(int value);

    virtual ~Integer();
};


