/* Generic Printer using function template */
#include <iostream>

template <class T>
void print(std::initializer_list<T> val){
    for(const auto& i : val)
    {
        std::cout << i << " ";
    }
    std::cout << "\n";
} 



int main() {
    print({1,2,3,5});
    print({'a','b','c'});

    return 0;
}