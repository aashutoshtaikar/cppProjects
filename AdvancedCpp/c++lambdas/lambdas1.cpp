#include<iostream>
using namespace std;

void test(void(*pFunc)(string)){
    pFunc("Called from test function(pfunction): Tom");
}

double testtype(double(*pdiv)(double, double)){
    auto val = pdiv(9,3);
    cout << val << endl;
}

int main(){

    auto func = [](string name){
        cout << "Name:" << name << endl;
    };

    func("called normally: Mike");
    
    test(func);

    auto func1 = [](double a, double b){
        return a/b;
    };

    cout << testtype(func1) << endl;

    auto pdivide = [](double a, double b)->double{
        if(b==0){
            return 0;   //deduced return type "double" conflicts with previously deduced type "int"
        }               //cpp auto keyword is having trouble determining the return types. we have to specify using trailing return type.
        return a/b;
    };

    cout << pdivide(10.0,5.0) << endl;
    cout << pdivide(10.0,0.0) << endl;
    
    cout << testtype(pdivide) << endl;
}