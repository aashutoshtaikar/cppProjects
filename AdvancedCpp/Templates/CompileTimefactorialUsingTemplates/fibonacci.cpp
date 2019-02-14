#include<iostream>

/* regular recursive function */
size_t regFibonacci(size_t n){
    if(n<=1){
        return 1;
    }
    return regFibonacci(n-1) + regFibonacci(n-2);
}

void runRegFibonacci(){
    std::cout << regFibonacci(2);
}

template<size_t n> 
struct fibonacci;

template<>
struct fibonacci<0>
{
    const static auto value = 1;
};

template<>
struct fibonacci<1>
{
    const static auto value = 1;
};


template<size_t n>
struct fibonacci
{
    const static auto value = fibonacci<n-1>::value + fibonacci<n-2>::value;
};

int main(){
    std::cout << fibonacci<4>::value << '\n';
}