#include<iostream>
using namespace std;

//C++98 no optimizations 
//Turn off optimizations in C++11 by passing -fno-elide-constructors to compiler

class Test{
private:
    int x{};
public:
    Test(){
        cout << "default constructor" << endl;
    }

    Test(int i){
        cout << "int constructor" << endl;
        x = i;
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

    Test &operator<<(const Test &other){
        this->x = (this->x << other.x); 
//        cout << this->x << " " << other.x;
    }

    int getX()const{
       return this->x;
    }

    Test getThis()const{
        return *this;
    }

    //  friend ostream &operator<<(ostream &out, const Test &test);

    ostream& print(ostream &out) const{     //ostream getter
        out << "hello" << endl;
    }

};

    // ostream &operator<<(ostream &out, const Test &test){
    //     out << "hello from test";
    //     return out;
    // }

    ostream& operator<<(ostream &out, const Test &test){
        return test.print(out);
    }

Test getTest(){
    return Test();
}

int main(){
    Test test1 = getTest();
    cout << test1 << endl;

    Test test2(1);
    Test test3(1);
    test2 << test3;
    cout << endl << test2.getX();

    return 0;
}