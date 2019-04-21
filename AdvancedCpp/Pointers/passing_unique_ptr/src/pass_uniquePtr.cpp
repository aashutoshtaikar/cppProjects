/* Different ways of passing unique_ptr<T[]> to a function 
    References:
    https://rufflewind.com/2016-03-05/unique-ptr
 */
#include <iostream>
#include <memory>   //smart pointers

void foo(std::unique_ptr<int[]>* x, int size){
    for(int i = 0; i<size; i++){
        //std::cout << (*x).get()[i] << "\n"; 
        std::cout << (*x)[i] << " ";
    }
    std::cout << "\n";
}

void bar(std::unique_ptr<int[]>& x, int size){
    for(int i = 0; i<size; i++)
    {
        std::cout << x[i] << " ";  
    }
    std::cout << "\n"; 
}

void baz(int* x, int size){
    for(int i = 0; i<size; i++)
    {
        std::cout << x[i] << " ";  
    }
    std::cout << "\n";
}

int main(){
    using namespace std;

    std::unique_ptr<int[]> x(new int[4]{1,5,3,4});
    foo(&x,4);
    bar(x,4);
    baz(x.get(),4);  //getting raw pointer


    return 0;
}