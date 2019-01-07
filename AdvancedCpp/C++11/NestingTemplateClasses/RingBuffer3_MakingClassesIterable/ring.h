#ifndef RING_H_
#define RING_H_

#include<iostream>
#include<vector>
using namespace std;

template<class T>
class ring{
private:
    T *m_values;
    int m_size;
    int m_pos;
    
public:
    class iterator; //declaration

    ring(int size):m_pos(0), m_values(new T[size]{}), m_size(size){}

    void add(T name){
        m_values[m_pos % m_size]=name;
       m_pos++;
    }

    T &getRing(int pos){
        return m_values[pos];
    }

    int size(){
        return m_size;
    }

    iterator begin(){
        return iterator(0,*this);
    }

    iterator end(){
        return iterator(m_size,*this);
    }

    virtual ~ring(){
        delete [] m_values;
    }
};

//nested class implementation
template<class T>
class ring<T>::iterator{
private:
    int m_pos;
    ring &m_ring;
public:
    iterator(int pos, ring &aRing):m_pos(pos),m_ring(aRing){}

    iterator &operator++(){
        m_pos++;
        return *this;
    }

    iterator &operator++(int){
        iterator temp = *this;
        ++*this;
        return *this;
    }

    T &operator*(){
        return m_ring.getRing(m_pos);
    }

    bool operator!=(const iterator &other) const{
        return m_pos != other.m_pos;
    }
};



#endif