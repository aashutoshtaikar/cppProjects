#include<iostream>

using namespace std;

//1. auto with trailing return type (->)
template<class T>
auto autoTest(T value) -> decltype(value){

    return value;
}

//2. regular template
template<class T>
T regularTemplate(T value) {

    return value;
}

//3. using expressions in decltype
template<class T, class S>
auto autoTest2x(T value1, S value2) -> decltype(value1+value2){

    return value1+value2;
}

//4. using the return values of another function
int get(){
    return 999;
}

auto autoTest3x() ->decltype(get()){
    return get();
}



//5. auto return type works in c++14 without template/decltype 
/* 
auto autoTestc14x(){
    return 1;
} 
*/

int main(){
    auto value = 7;
    auto text = "Hello";

    cout << autoTest("hey") << endl;
    cout << regularTemplate("hey") << endl;

    cout << autoTest2x(5,6) << endl;
    cout << autoTest3x() << endl;


    //cout << autoTestc14x() << endl;

    return 0;
}