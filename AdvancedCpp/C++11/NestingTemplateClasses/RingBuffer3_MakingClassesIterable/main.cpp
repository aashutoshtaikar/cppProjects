#include<iostream>
#include"ring.h"
using namespace std;


int main(){
    // ring<int>::iterator it;
    // it++;
    // it.print();
    // cout << (*it) << endl;

    ring<string> textstring(3);

    textstring.add("one");
    textstring.add("two");
    textstring.add("three");
    textstring.add("four");
    textstring.add("five");

    //to make classes iterable 
    //C++98 style
    for(ring<string>::iterator it = textstring.begin();it!=textstring.end();it++){
        cout << *it << endl;
    }

    cout << endl;

    //C++11 style
    for (string value:textstring){
        cout << value << endl;
    }
    
    return 0;    
}