//gcc 7.3 uses C++11 flag as default; for lower gcc versions use -std=C++11 -std=gnu++11 complilation flag 

#include<iostream>
#include<typeinfo>      //for using typeid()
//#include<string>        //not required for newer gcc versions
using namespace std;


/* Name Mangling: C++ bin file needs more info about the context, takes the names of vars and functions and it adds loaded characters 
function names, overloaded function, vars   
if we use typeid for strings it gives out a mangled name
*/

int main(){

    string value;

    //C++ 11 specifics
    decltype(value) name = "Bob";   //decltype returns the type of an existing variable; used to declare variables of an existing type

    cout << typeid(value).name() << endl;
    
    cout << name << endl;

    return 0;
}