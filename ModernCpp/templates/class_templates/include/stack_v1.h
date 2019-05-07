#pragma once
/* incomplete implementation 
    realloc: If ptr is NULL, the behavior is the same as calling malloc(new_size).
*/
#include <stdlib.h>

namespace ayt{

template<class stack_t>
class stack
{
private:
    stack_t m_nullvalue;
    stack_t* m_Buffer{nullptr};
    int alloc_size{10};
    int m_Top;

private:
    void alloc(){
        if (m_Top == alloc_size) alloc_size *= 2;
        m_Buffer = (stack_t*) realloc (m_Buffer, sizeof(stack_t) * alloc_size); //allocate 10
    }

    // deallocate by 10
    void dealloc(){
        if(alloc_size-m_Top > alloc_size){ 
            alloc_size /= 2;    
            m_Buffer = (stack_t*) realloc (m_Buffer, sizeof(stack_t) * alloc_size);  
        }
    }

public:
    class iterator;

public:

    template<class val_t, class...rest_t>
    stack(val_t&& val,rest_t&&... rest){
        push(val);
        push(rest...);
    }

    template<class T>
    void push(T&& val){
        if(m_Top==0 || m_Top==alloc_size) alloc();
        m_Buffer[m_Top] = val;
        m_Top++;
    }

    template<class val_t, class...rest_t>
    void push(val_t&& val,rest_t&&... rest){
        if(m_Top==0 || m_Top==alloc_size) alloc();
        m_Buffer[m_Top] = val;
        m_Top++;
        push(rest...);
    }

    void pop(){
        --m_Top;
        m_Buffer[m_Top] = NULL;
        dealloc();
    }

    stack_t top()const{
        return m_Buffer[m_Top];
    }

    int size()const{
        return m_Top;
    }

    int capacity()const{
        return alloc_size;
    }

    stack_t& get(int pos){
        if(pos <= m_Top) return m_Buffer[pos];
        std::cerr << "Error: value out of range\n";
        return m_nullvalue;
    }

    iterator begin(){
        return iterator(0, *this);
    }

    iterator end(){
        return iterator(m_Top, *this);
    }

    virtual ~stack(){
        delete[] m_Buffer;
    }
};

template<class stack_t>
class stack<stack_t>::iterator{
private:
    int m_itTop;
    stack& m_stack;
public:
    iterator(int top, stack& stk):m_itTop(top),m_stack(stk){}

    iterator& operator++(){
        m_itTop++;
        return *this;
    }

    iterator& operator++(int){
        m_itTop++;
        return *this;    
    }

    stack_t& operator*(){
        return m_stack.get(m_itTop);
    }

    bool operator!=(const iterator& other){
        return m_itTop!=other.m_itTop;
    }

    bool operator==(const iterator& other){
        return m_itTop==other.m_itTop;
    }
    
};


}

/*  
Problems/bugs in the previous implementation:
1. Constructor with variadic templates cannot have a recursive implementation
2. Returning a [m_top] value in the get method instead of the [pos] 
*/