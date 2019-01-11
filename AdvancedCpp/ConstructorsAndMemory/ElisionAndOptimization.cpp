#include<iostream>
using namespace std;

//C++98 no optimizations 
//Turn off optimizations in C++11 by passing -fno-elide-constructors to compiler

class Test{
public:
    Test(){
        cout << "default constructor" << endl;
    }

    Test(int i){
        cout << "int constructor" << endl;
    }

    Test(const Test &other){
        cout << "copy constructor" <<endl;
    }

    Test &operator=(const Test &other){
        cout << "overloading assignment operator" << endl;
        return *this;
    }

    ~Test(){
        cout << "destructor" <<endl;
    }

    friend ostream &operator<<(ostream &out, const Test &test);

};

    ostream &operator<<(ostream &out, const Test &test){
        out << "hello from test";
        return out;
    }

Test getTest(){
    return Test();  //creates a default constructor
}                   //when function return objects they have to copy those objects, thus runs copy constructor
                    //copies the obj into temporary return value

int main(){
    Test test1 = getTest();         //copying the temporary return value object to test1 object, thus runs a copy constructor
    //test1 = testx //runs assignment
    cout << "------------" << endl;
    cout << test1 << endl;

    return 0;
}