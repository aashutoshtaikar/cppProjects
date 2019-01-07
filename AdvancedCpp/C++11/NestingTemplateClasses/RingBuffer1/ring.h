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
    
public:
    class iterator;
    static int cnt;

    ring(int size):m_values(new T[size]{}),m_size(size){}

    void add(T name){
        m_values[this->cnt % m_size]=name;
        this->cnt++;
    }

    T getRing(int num) const{
        return this->m_values[num];
    }

    int size(){
        return this->m_size;
    }

    virtual ~ring(){
        delete [] m_values;
    }
};

template<class T>
int ring<T>::cnt = 0;



template<class T>
class ring<T>::iterator{

public:
    int count;

    iterator():count(cnt){}

    iterator &operator++(){
        count++;
        return *this;
    }

    iterator &operator++(int){
        iterator temp = *this;
        ++*this;
        return *this;
    }

    void print(){
        cout << "hello from iterator" << endl;
        cout << T() << endl;
        cout << this->count;
        

    }

    // T &operator*(const iterator& it){
    //     return it.getRing(cnt);  
    // }

};



// int iterator count = 0;



#endif