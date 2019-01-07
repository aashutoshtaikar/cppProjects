#include<iostream>
#include"ring.h"

using namespace std;

/* 
sudo apt-get install libcurl4-gnutls-dev
"/usr/include/x86_64-linux-gnu/curl"
#include<curl/curl.h>
*/

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

    for(int i=0; i < textstring.size();i++){
        cout << textstring.getRing(i) << endl;
    }
    
    return 0;    
}