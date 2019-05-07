#include <iostream>
/* Regular recursive function */
int regFactorial(size_t n){
    if(n==0){       
        return 1;
    }
    return n * regFactorial(n-1);
}

void runRegFactorial() {
    std::cout << regFactorial(2) << std::endl;
    std::cout << regFactorial(3) << std::endl;
}

/* Using Template to perform recursion : math at compile time*/
template<size_t n> struct factorial;    //incomplete declaration

template<>              //Base case
struct factorial<0>{
    const static auto value = 1;
};

template<size_t n>      //recursive definition
struct factorial{
    const static auto value = n * factorial<n-1>::value;
};


int main() {
    std::cout << factorial<2>::value << std::endl;
    std::cout << factorial<3>::value << std::endl;
    static_assert(factorial<3>::value == 6, "factorial math problem");
}