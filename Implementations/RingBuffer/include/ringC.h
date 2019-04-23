#pragma once

namespace RingBuffer
{

template <class T>
class ringC{
private:
    T m_nullvalue;
    int m_pos;
    int m_size;
    T* m_values;
public:
    class iterator;

public:
    ringC(int size):m_nullvalue{},m_pos(0),m_size(size),m_values(new T[size]){}
    
    ~ringC(){
        delete [] m_values;
    }

    int size()const{
        return m_size;
    }

    // template <class U, class... Tpack>
    // void add(U&& value, Tpack&&... args){
    //     m_values[m_pos] = static_cast<T>(value);
    //     m_pos++;
    //     if (m_pos == m_size) m_pos = 0;
    //     add(args...);
    // }
    
    template<class U>
    void add(U&& value){
        using U = T;
        m_values[m_pos] = static_cast<U>(value);
        m_pos++;
        if (m_pos == m_size) m_pos = 0;
    }

    T& get(int pos){
        if(pos < m_size) return m_values[pos];
        else{
            std::cerr << "error: value out of range\n";
            return m_nullvalue;
        }
    }

    //getting iterators
    iterator begin(){
        return iterator(0, *this);
    }

    iterator end(){
        return iterator(m_size, *this);
    }
    
};

template <class T>
class ringC<T>::iterator{
private:
    int m_itpos;
    ringC& m_ring;
public:
    iterator(int pos, ringC& aring):m_itpos(pos), m_ring(aring){}

    iterator& operator++(){
        m_itpos++;
        return *this;
    }
    
    iterator& operator++(int){
        m_itpos++;
        return *this;
    }

    T& operator*(){
        return m_ring.get(m_itpos);
    }

    bool operator!=(const iterator& otherit){
        return m_itpos!=otherit.m_itpos;
    }

    bool operator==(const iterator& otherit){
        return m_itpos==otherit.m_itpos;
    }
};



} // RingBufer
