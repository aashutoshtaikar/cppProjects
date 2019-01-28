#include<iostream>

/* example class */
class Entity{
public:
    Entity(){
        printf("Entity created\n");
    }
    ~Entity(){
        printf("Entity destroyed\n");
    }
};

/* scoped pointer */
template<class T>
class ptr_To{
    T* m_ptr;

public:
    ptr_To(T* p):m_ptr(p){}

    ~ptr_To(){
        delete m_ptr;
    }
};

// template<class T>
// class mutexlock{
//     T*
// };


int main(){
    ptr_To<Entity> e = new Entity();    //scoped poiter

    //another use : mutex lock to not let multiple threads access a function

}