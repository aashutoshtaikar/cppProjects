#include<iostream>
#include<string>
#include<vector>
using namespace std;

//C++98 initializations

int main(){
    int values[] = {1,2,3};

    /* objects of classes and structs can be initialized as follows: (in order of their public member variables) */ 
    class C{
    public:
        string text;
        int id;
    };

    C c1 = {"hello",7};

    //usually used for structs
    struct S{
        string text;
        int id;
    };

    S s1 = {"hello",7};

    struct Sx{
        string text;
        int id;
    } s2 = {"hello",5}, s3 = {"tom",3};


    //struct without name
    struct {
        string text;
        int id;
    } s4 = {"hello",5}, s5 = {"tom",3};

    cout << s4.text << endl;
    cout << s5.text << endl;

    //tedious form of initialization
    vector<string> strings;

    strings.push_back("one");
    strings.push_back("two");
    strings.push_back("three");
    

    return 0;
}