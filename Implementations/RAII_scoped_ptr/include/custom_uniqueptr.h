#pragma once

namespace ayt{

template <typename T>
class unique_ptr
{
private:
    T* m_ptr;
    bool m_owns;

public:
    unique_ptr():m_ptr(nullptr), m_owns(false){}

    // unique_ptr(const T& val):m_ptr(val), m_owns(true){}
    unique_ptr(T* val):m_ptr(val), m_owns(true){}

    //return a raw pointer
    T* get(){
        if(m_owns) {
            return m_ptr;
        }
    }

    //release ownership and return raw pointer
    T* release(){
        if(m_owns){
            m_owns = false;
            return m_ptr;
        }
        else{
            return nullptr;
        }
    }

    //delete this->pointer -- invoke destructor
    void reset(){
        if(m_owns){
            m_owns = false;
            delete m_ptr;
        }
    }

    unique_ptr(const unique_ptr& other) = delete;
    unique_ptr& operator=(const unique_ptr& other) = delete;
    
    unique_ptr(unique_ptr&& other){
        m_ptr = other.m_ptr;
        m_owns = other.m_owns;

        other.m_ptr = nullptr;
        other.m_owns = false;
    }
    
    unique_ptr& operator=(unique_ptr&& other){
        if (m_owns){        //de-allocate prev allocated mem to prevent mem leak
            m_owns = false;
            delete m_ptr;
        } 

        m_ptr = other.m_ptr;
        m_owns = other.m_owns;

        other.m_ptr = nullptr;
        other.m_owns = false;
        
        return *this;
    }

    T operator*(){
        return *m_ptr;
    }

    //destructor
    ~unique_ptr(){
        if(m_owns){
            delete m_ptr;
            m_owns = false;
        }
    }
};

template<typename T>
unique_ptr<T> make_unique(T& val){
    return unique_ptr<T>(new T(val));
}

// //create partial specialization for array types
// template<typename T>
// class unique_ptr<T[]>
// {
// private:
//     T* m_ptr;
//     bool m_owns;

// public:
//     unique_ptr():m_ptr(nullptr), m_owns(false){}

//     // unique_ptr(const T& val):m_ptr(val), m_owns(true){}
//     unique_ptr(T* val):m_ptr(val), m_owns(true){}

//     //return a raw pointer
//     T* get(){
//         if(m_owns) {
//             return m_ptr;
//         }
//     }

//     //release ownership and return raw pointer
//     T* release(){
//         if(m_owns){
//             m_owns = false;
//             return m_ptr;
//         }
//         else{
//             return nullptr;
//         }
//     }

//     //delete this->pointer -- invoke destructor
//     void reset(){
//         if(m_owns){
//             m_owns = false;
//             delete m_ptr;
//         }
//     }

//     unique_ptr(const unique_ptr& other) = delete;
//     unique_ptr& operator=(const unique_ptr& other) = delete;
    
//     unique_ptr(unique_ptr&& other){
//         m_ptr = other.m_ptr;
//         m_owns = other.m_owns;

//         other.m_ptr = nullptr;
//         other.m_owns = false;
//     }
    
//     unique_ptr& operator=(unique_ptr&& other){
//         if (m_owns){        //de-allocate prev allocated mem to prevent mem leak
//             m_owns = false;
//             delete m_ptr;
//         } 

//         m_ptr = other.m_ptr;
//         m_owns = other.m_owns;

//         other.m_ptr = nullptr;
//         other.m_owns = false;
        
//         return *this;
//     }

//     T operator*(){
//         return *m_ptr;
//     }

//     //destructor
//     ~unique_ptr(){
//         if(m_owns){
//             delete[] m_ptr;
//             m_owns = false;
//         }
//     }
// };

}