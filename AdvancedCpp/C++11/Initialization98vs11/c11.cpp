#include<iostream>
#include<vector>
using namespace std;

int main(){

    int value{5};
    cout << value << endl;

    string text{"hello"};
    cout << text << endl;

    int numbers[]{1,2,3};
    cout << numbers[1] << endl;

    //initializing pointer to an array
    int *pInts = new int[3]{1,2,3};
    cout << pInts[1] << endl;
    delete pInts;

    //empty braces initialized to 0 for string it will be an empty string ""
    int value1{};
    cout << value1 << endl;

    //initialize a pointer to another existing pointers 
    int *pSomething{&value};
    cout << *pSomething << endl;

    //c++11 default nullptr init 
    int *pSomethingx{};         //*pSomethingx{nullptr} OR *pSomethingx = nullptr
    cout << pSomethingx << endl;


    int numbers1[5]{};
    cout << numbers1[1] << endl;

    struct {
        int value;  
        string text;
    } s1{1,"hello"};    

    vector<string> strings{"one","two","three"};
}

/* output:
5
hello
2
2
0
5
0
 */