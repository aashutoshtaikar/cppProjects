#include <iostream>
<<<<<<< HEAD
#include "stack_test.h"

int main() {
    using namespace ayt;
    stack<int> x(1,2,3,4,5,6,7,8,9,10,11);
    x.push(2, 5, 6);

    std::cout << "Size:" << x.size() << "\n";
    std::cout << "Capacity:" << x.capacity() << "\n";

    for(auto i : x){
        std::cout << i << " ";
    }
    std::cout << "\n";
    // stack<int> y(15,12);
    // std::cout << y.capacity(); 
=======
#include "stack.h"

int main() {
    using namespace ayt;
    stack<int> x(1,2,3,4);
    std::cout << x.size();

    for(auto i : x){
        std::cout << i << " ";
        // std::cout << x.top();
    }
>>>>>>> 05dd884fb5f0597eb5298e0e0cf86203e4c5ed4c
}