#pragma once 
#include <iostream>

class Integer
{
private:
    int* m_pInt{nullptr};

public:
    Integer(){}

    Integer(int val):m_pInt(new int(val)){}

    Integer(const Integer& other){
        m_pInt = new int(other.get());
    }

    Integer& operator=(const Integer& other){
        if (this != &other){
            delete m_pInt;
            m_pInt = new int(other.get()); //deep copy
        }
        return *this;
    }

    Integer(Integer&& other){
        m_pInt = other.m_pInt;
        other.m_pInt = nullptr;
    }

    Integer& operator=(Integer&& other){
        if (this != &other){
            delete m_pInt;
            m_pInt = other.m_pInt;
            other.m_pInt = nullptr;
        }
    }

    std::ostream &print_out(std::ostream &out) const{
        out << this->get();
        return out;
    }

    friend std::ostream& operator<<(std::ostream& out, const Integer& other){
        // out << other.get();
        // return out;
        return other.print_out(out);
    }

    void operator<<(const Integer& other){
        *this = other;
    }

    void operator>>(Integer& other){
        other = *this;
    }

    int& get()const{
        return *m_pInt;
    }

    virtual ~Integer(){
        delete m_pInt;
    }
};

