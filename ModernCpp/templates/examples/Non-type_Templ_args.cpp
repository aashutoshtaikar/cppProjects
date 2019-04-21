#include <iostream>
#include <string.h>

//non type template arguments take const args
template<int size>
void Print(){
    char buffer[size];
    std::cout << size << "\n";
}

//function returns the sum of element of an array
template<typename T>
T Sum(T* pArr, int size){
    T sum{};
    for(int i = 0; i < size; i++)
    {
        sum += pArr[i];
    }
    return sum;
}

template<typename T, int size>
T auto_sum(T (&pArr)[size]){
    T sum{};
    for(int i = 0; i < size; i++)
    {
        sum += pArr[i];
    }
    return sum;
}

int test_Print(){
    Print<3>();         //works
    const int i = 3;    
    Print<i>();         //works
    
    int j = 3;
    // Print<j>();      //cannot work as j is not constant
    Print<sizeof(j)>(); //works
}

int test_sum(){
    int arr[]{3,4,2,7};
    int sum = Sum(arr,4);
    int(&ref)[4] = arr;     //reference to an array
    // int(&ref)[5] = arr; //will not work as arr size is [4] and ref size is[5] 
}

int test_autosum(){
    using namespace std;
    int arr[]{1,2,3,4};
    // int(&ref)[4] = arr;     //reference to an array, using this principle and non-type we can implement
    cout << auto_sum(arr);

    return 0;
}



int main(){
    // test_Print();
    test_autosum();


    return 0;
}