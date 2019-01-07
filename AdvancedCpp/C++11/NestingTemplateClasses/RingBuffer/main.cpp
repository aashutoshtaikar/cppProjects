#include<iostream>
#include"ring.h"
using namespace std;


int main(){
    ring<int>::iterator it;
    it++;
    it.print();
    // cout << (*it) << endl;

    ring<string> textstring;

    textstring.add("one");
    textstring.add("two");
    textstring.add("three");
    textstring.add("four");

    for(int i=0; i < textstring.size();i++){
        cout << textstring.getRing(i) << endl;
    }
    
    return 0;    
}