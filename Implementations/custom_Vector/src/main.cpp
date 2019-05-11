#include <iostream>
#include "stack_v1.h"
#include "stack_test.h"


class stack_test{
public:
    static void test1(){
        using namespace test_ayt;
        stack<int> x(1, 2, 3);
        std::cout << x.size() << "\n";

        for (auto i : x)
        {
            std::cout << i << "-";
            // std::cout << x.top();
        }
    }
};

class test_stack_v1{
public:
    static void test1(){
        using namespace ayt;
        stack<int> x(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11);
        x.push(2, 5, 6);

        std::cout << "Size:" << x.size() << "\n";
        std::cout << "Capacity:" << x.capacity() << "\n";

        for (auto i : x)
        {
            std::cout << i << " ";
        }
        std::cout << "\n";
        // stack<int> y(15,12);
        // std::cout << y.capacity();
    }
};



int main() {
    // stack_test::test1();
    test_stack_v1::test1();

    std::cin.get();
    return 0;
}