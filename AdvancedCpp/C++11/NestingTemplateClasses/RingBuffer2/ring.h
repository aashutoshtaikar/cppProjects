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
    class iterator;

    ring(int size):m_pos(0), m_values(new T[size]{}),m_size(size){}

    void add(T name){
        m_values[m_pos % m_size]=name;
        m_pos++;
    }

    T getRing(int num) const{
        return m_values[num];
    }

    int size(){
        return m_size;
    }

    virtual ~ring(){
        delete [] m_values;
    }
};




// template<class T>
// class ring<T>::iterator{

// public:
//     int count;

//     iterator():count(cnt){}

//     iterator &operator++(){
//         count++;
//         return *this;
//     }

//     iterator &operator++(int){
//         iterator temp = *this;
//         ++*this;
//         return *this;
//     }

//     void print(){
//         cout << "hello from iterator" << endl;
//         cout << T() << endl;
//         cout << this->count;
        

//     }

//     // T &operator*(const iterator& it){
//     //     return it.getRing(cnt);  
//     // }

// };



// int iterator count = 0;



#endif