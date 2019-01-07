#ifndef RING_H_
#define RING_H_

#include<iostream>
#include<vector>
using namespace std;

template<class T>
class ring{
    vector<T> vName;
public:
    class iterator;

    ring():vName{}{}

    void add(T name){
        vName.push_back(name);
    }

    T getRing(int num) const{
        return vName[num];
    }

    int size(){
        return vName.size();
    }

};


template<class T>
class ring<T>::iterator{
private:
    int cnt;
    ring &m_ring;
public:
    iterator():cnt(0),m_ring(){}

    iterator &operator++(){
        cnt++;
        return *this;
    }

    iterator &operator++(int){
        iterator temp = *this;
        ++*this;
        return *this;
    }

    void print(){
        // cout << "hello from iterator" << endl;
        // cout << T() << endl;
        // cout << this->cnt;
        cout << getRing(cnt);

    }

    // T &operator*(const iterator& it){
    //     return it.getRing(cnt);  
    // }

};



#endif