#include<iostream>

/* constexpr : another way of executing at compile time
c++14 : multiline constexpr*/
constexpr size_t fib_cpp14(size_t n){
    if(n<=1){
        return 1;
    }
    return fib_cpp14(n-1) + fib_cpp14(n-2);
}

/* c++11 : single line constexpr allowed*/
constexpr size_t fib_cpp11(size_t n){
    return n <= 1 ? 1 : fib_cpp11(n-1) + fib_cpp11(n-2);
}

static_assert(  //works at compile time
    fib_cpp11(4) ==5,
    "compile time math error"
);

int main(){
    std::cout << fib_cpp14(4) << '\n';
}