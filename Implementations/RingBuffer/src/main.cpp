#include <iostream>
#include <string>
#include "ringA.h"
#include "ringB.h"
#include "ringC.h"

using namespace std;
namespace rb = RingBuffer;

void test_ringA(){
    rb::ringA<std::string> textring(3);

    textring.add("one");
    textring.add("two");
    textring.add("three");
    // textring.add({"four","five","six"});

    // for(int i = 0; i < textring.size(); i++){
    //     cout << textring.get(i) << endl;
    // }
    // cout << textring.get(4);

    for(rb::ringA<std::string>::iterator it = textring.begin(); it!=textring.end(); it++){
        cout << *it << endl;
    }

    for(auto&& i : textring){
        cout << i << endl;
    }
}

void test_ringB(){
    rb::ringB<std::string> textring(3);

    textring.add({"one"});
    textring.add({"two"});
    textring.add({"three"});
    // textring.add({"four","five","six"});

    // for(int i = 0; i < textring.size(); i++){
    //     cout << textring.get(i) << endl;
    // }
    // cout << textring.get(4);

    for(rb::ringB<string>::iterator it = textring.begin(); it!=textring.end(); it++){
        cout << *it << endl;
    }

    for(auto&& i : textring){
        cout << i << endl;
    }
}

void test_ringC(){
    rb::ringC<std::string> textring(3);
<<<<<<< HEAD
    textring.add("one", 2, "three", "four", "five");
    // textring.add("one");
    // textring.add("one");
    // textring.add("three");
=======

    textring.add(std::string{"one"});
    textring.add(2);
    textring.add(std::string{"three"});
>>>>>>> 05dd884fb5f0597eb5298e0e0cf86203e4c5ed4c
    // textring.add("four","five","six");

    // for(int i = 0; i < textring.size(); i++){
    //     cout << textring.get(i) << endl;
    // }
    // cout << textring.get(4);

    for(rb::ringC<string>::iterator it = textring.begin(); it!=textring.end(); it++){
        cout << *it << endl;
    }

    for(auto&& i : textring){
        cout << i << endl;
    }
}

int main() {
    test_ringC();
    
    

    return 0;
}