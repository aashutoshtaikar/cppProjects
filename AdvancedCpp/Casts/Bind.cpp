#include <iostream>
#include <functional>        //for bind 

using namespace std;         //for bind
using namespace placeholders;  

//bind a function
int add(int a, int b, int c){
    cout << a << "," << b << "," << c << endl;
    return a+b+c;
}

//bind to another function 
int run(function<int(int,int)> func){
   return func(7,3);
}

//bind to a method
class Test{
public:
    int add(int a, int b, int c){
        cout << a << "," << b << "," << c << endl;
        return a+b+c;
    }
};

int main(){
    auto calculate = bind(add, 1,2,3);
    cout << calculate() << endl;

    auto calculate1 = bind(add, _1,_2,_3);   //for actual args to be passed in calculate
    cout << calculate1(10,20,30) << endl;    //_1,_2,_3 are passed in in their numbered order

    auto calculate2 = bind(add, _2,_1,_3);   //for actual args to be passed in calculate
    cout << calculate2(10,20,30) << endl;    //_1,_2,_3 are passed in in their numbered order

    auto calculate3 = bind(&add, _2, 100, _1);   //100 -- hard args
    cout << calculate3(10,20) << endl;          

    //bind to another function 
    cout << run(calculate3) << endl;

    //bind to a method
    Test test;
    auto calculate4 = bind(&Test::add, test, _2,100,_1);
    cout << run(calculate4) <<endl;

    //bindind static methods -- example codes can be found on stack ov


    return 0;
}