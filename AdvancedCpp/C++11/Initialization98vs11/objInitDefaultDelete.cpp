#include<iostream>
#include<vector>
//#include<initializer_list>
using namespace std;

class Test{
    int id { 8 };
    string name { "Mike" };

public:
    Test() = default;    //added functionality: replaced an implicit constructor that we lost due to the constructor with arg(id) below

    Test(const Test &other) = default; // No added functionality: just making it clear to use the default copy constructor and assignment operator
    Test &operator=(const Test &other) = delete;   //replace default with delete to delete the default constructor or assignment operator

    Test(int id):id(id){}

    void print(){
        cout << id << ":" << name << endl;
    }
};

int main(){

    Test test;
    test.print();

    Test test1(77);
    test1.print();

    
    Test test3(test);   //invokes the copy constructor 
    test3.print();

    Test test4 = test;  //invokes the copy constructor 
    test4.print();

    /*  deleted the default object assingment operator
    test4 = test1;      //invokes the object assignment operator 
    test4.print(); 
    */


    return 0;
}