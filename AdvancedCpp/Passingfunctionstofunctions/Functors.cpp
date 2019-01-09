#include <iostream>
#include<string>
using namespace std;

/* 
Virtual Destructors necessity: Deleting a derived class object using a pointer to a base class that has a non-virtual destructor results in undefined behavior. To correct this situation, the base class should be defined with a virtual destructor.

functors: passing blocks of code to functions // alternative to function pointers - 
advantage over function pointers: A functor(struct/class) can have a state(private vars)
In c++11 lambdas are simpler alternative to functors 
 */

//base class , struct used for default public access
struct Test{     //overloading the () operator - can take one or more agrs

    virtual bool operator()(string &txt) = 0;  // txt doesn't have to be a reference

    virtual ~Test(){}
};

//lots of different tests all derived from base class
//functor is a struct/class that does other operations along with overloading () operator
struct MatchTest:public Test{       //can have private variables
    bool operator()(string &txt){
        return txt == "lion";
    }
};

struct NewMatchTest:public Test{       //can have private variables
    bool operator()(string &txt){
        return txt == "tiger";
    }
};

//tests different kinds of strings/predicates
void check(string txt, Test &test){    //passing polymorphic references to functions 
    if(test(txt)){                          //application of () operator
        cout << "Text matches" << endl;
    }
    else{
        cout << "No match" << endl;
    }
}

int main(){
    MatchTest pred;
    string value = "lion";
    cout << pred(value) << endl;    //application of () operator
    value = "liond";
    cout << pred(value) << endl;    //application of () operator

    cout << "--------------" << endl;
    
    MatchTest m;
    check("lion",m);

    NewMatchTest nm;
    check("tiger",nm);

    return 0;
}