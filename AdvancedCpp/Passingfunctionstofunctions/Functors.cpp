#include <iostream>
#include<string>
using namespace std;

//Deleting a derived class object using a pointer to a base class that has a non-virtual destructor results in undefined behavior. To correct this situation, the base class should be defined with a virtual destructor.
//functors: passing blocks of code to functions // alternative to function pointers - 
// in c++11 lambdas are used instead of functors


struct Test{
    virtual bool operator()(string &text) = 0;

    virtual ~Test(){}
};

struct MatchTest:public Test{
    bool operator()(string &text){
        return text == "lion";
    }
};

//tests the string
void check(string text, Test &test){
    if(test(text)){
        cout << "Text matches" << endl;
    }
    else{
        cout << "No match" << endl;
    }
}

int main(){
    MatchTest pred;
    string value = "lion";

    cout << pred(value) << endl;
    
    MatchTest m;

    check("lion",m);

    return 0;
}