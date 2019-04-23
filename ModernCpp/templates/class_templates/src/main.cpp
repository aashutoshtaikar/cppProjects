#include <iostream>
#include "stack.h"

int main() {
    using namespace ayt;
    stack<int> x(1,2,3,4);
    std::cout << x.size();

    for(auto i : x){
        std::cout << i << " ";
        // std::cout << x.top();
    }
}