#pragma once
/* Ring buffer: 
    -values allocated on heap
    -iterable class with iterator
    -with variable constructor args -- initializer list
 */
namespace RingBuffer{
#include <initializer_list>
template <class T>
class ringB{
private:
    T m_nullvalue{};
    int m_pos;
    int m_size;
    T* m_values;

public:
    class iterator; //friend class

public:
    ringB(int size):m_nullvalue{},m_pos(0),m_size(size), m_values(new T[size]){}

    int size(){
        return m_size;
    }

    // void extend(int size){}
    void add(std::initializer_list<T> values){
        for(auto&& i : values){
            add_one(i);
        }
    }

    void add_one(T value){
        m_values[m_pos] = value;
        m_pos++;
        
        if (m_pos == m_size) {
            m_pos = 0;
        }
    }

    //value getter more efficient to return a reference, also normally STL containers return references to value in container
    T& get(int pos){
        if(pos<m_size) return m_values[pos];
        else {
            std::cerr << "error: value out of range\n";
            return m_nullvalue;
        }
    }

    //for getting iterators/changing iterator position
    iterator begin(){
        return iterator(0, *this);
    }

    iterator end(){
        return iterator(m_size, *this);
    }

    ~ringB(){
        delete [] m_values;
    }

};

template <class T>
class ringB<T>::iterator{
private:
    int m_pos;
    ringB& m_ringB;    
public:
    iterator(int pos, ringB& aRingB):m_pos(pos),m_ringB(aRingB){}
    
    //++it
    iterator& operator++(){
        m_pos++;
        return *this;
    }

    //++it
    iterator& operator++(int){
        m_pos++;
        return *this;
    }

    //checking condition
    bool operator!=(const iterator& other)const{
        return m_pos != other.m_pos;
    }

    bool operator==(const iterator& other)const{
        return m_pos == other.m_pos;
    }

    T& operator*()const{
        return m_ringB.get(m_pos);
    }

};

}   //namespace RingBuffer