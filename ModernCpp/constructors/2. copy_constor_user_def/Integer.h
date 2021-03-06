#pragma once

class Integer
{
private:
    int* m_pInt;
public:
    Integer();
    Integer(int value);

/*     copy constructor to initiate a deep copy
        because passing object by reference, to avoid modification of original objects qualify with const
 */
    Integer(const Integer& obj);

    int getValue();
    void setValue(int value);

    virtual ~Integer();
};


