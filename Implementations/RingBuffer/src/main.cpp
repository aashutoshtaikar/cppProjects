#include <iostream>
#include <string>
#include "ringA.h"
#include "ringB.h"
#include "ringC.h"

using namespace std;
using namespace RingBuffer;

template<class obj_t>
void run_test_on(obj_t ringObject){
        ringObject.add("one");
        ringObject.add("two");
        ringObject.add("three");

    // for(int i = 0; i < ringObject.size(); i++){
    //     cout << ringObject.get(i) << endl;
    // }
    // cout << ringObject.get(4);

    // for(ringA<std::string>::iterator it = ringObject.begin(); it!=ringObject.end(); it++){
    //     cout << *it << endl;
    // }
    for(auto&& i : ringObject){
        cout << i << endl;
    }
}

template<>
void run_test_on(ringB<string> ringObject){
    
    ringObject.add({"four","five","six"});

    // for(int i = 0; i < ringObject.size(); i++){
    //     cout << ringObject.get(i) << endl;
    // }
    // cout << ringObject.get(4);

    // for(ringA<std::string>::iterator it = ringObject.begin(); it!=ringObject.end(); it++){
    //     cout << *it << endl;
    // }
    for(auto&& i : ringObject){
        cout << i << endl;
    }
}


int main() {
    run_test_on(ringA<std::string>(3));
    run_test_on(ringB<std::string>(3));
    run_test_on(ringC<std::string>(3));

    return 0;
}