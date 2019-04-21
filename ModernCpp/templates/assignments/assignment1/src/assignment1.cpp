/* *Assignment1:
Convert the following functions into templates

int Add(int x,int y) ;                                  //Return the sum of two elements
int ArraySum(int *pArr, int arrSize);                   //Returns the sum of array elements
int Max(int *pArr, int arrSize) ;                       //Return the largest element in the array
std::pair<int,int> MinMax(int *pArr, int arrSize) ;      //Return the smallest and largest element in a pair

Take care to avoid copies of user-defined objects wherever applicable.
 */

#include <iostream>
#include <string>
#include <memory>   //unique_ptr<>
#include "assignment1.h"

void test_add(){
    using namespace std;
    cout << add(4, 5);
}

void test_ArraySum(){
    using namespace std;
    int x[] = {1, 5, 3, 4};
    cout << ArraySum(x, 4);
}

void test_Max(){
    using namespace std;
    std::unique_ptr<int[]> x(new int[4]{1, 5, 3, 4});
    cout << Max(x,4) << "\n";
}

void test_MinMax(){
    using namespace std;
    auto y = new float[4]{1.2, 5.5, 6.3, 4.1};
    auto pair = MinMax(y, 4);
    cout << "\n" << pair.first << " " << pair.second << "\n";
    delete[] y;
}


int main(){
    using namespace std;
    test_add();
    // test_ArraySum();
    // test_Max();
    // test_MinMax();

    return 0;
}