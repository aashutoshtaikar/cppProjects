#pragma once
#include<mutex>

namespace custom_locks{
template<typename T>
struct scoped_lock {
    T& m_mutex;
    scoped_lock(){} //base case
};

template<typename ...Params>
struct scoped_lock:{
    scoped_lock(T _m,Params... args):m_mutex{_m}{
        m_mutex.lock();
        scoped_lock(Params...);
    }

    ~scoped_lock(){
        m_mutex.unlock();
    }
};
}