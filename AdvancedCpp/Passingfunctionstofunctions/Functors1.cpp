#include <iostream>
#include<string>
using namespace std;

/* 
Virtual Destructors necessity: Deleting a derived class object using a pointer to a base class that has a non-virtual destructor results in undefined behavior. To correct this situation, the base class should be defined with a virtual destructor.
functors: passing blocks of code to functions // alternative to function pointers - 
advantage over function pointers: A functor(struct/class) can have a state(private vars)
In c++11 lambdas are used instead of functors 
 */

//base class
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
    
    Test *xtests[1];

    xtests[0] = new MatchTest();
    check("lion",*xtests[0]);

    xtests[1] = new NewMatchTest();
    check("tiger",*xtests[1]);

    // for(auto e: xtests){ //does not work
    //     delete e;
    // }

    for(int i = 0; i<=sizeof(xtests)/sizeof(*xtests);i++){
        delete xtests[i];
    }
    

    check("tiger",*xtests[1]);

    return 0;
}