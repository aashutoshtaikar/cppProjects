#include <iostream>

using namespace std;
//specify types to classes
//not easy to seperate implementation from class definition
//if implementation necessary put it in a non .cpp extension file

template<class T,class K>
class Test{
private:
    T obj;
public:
    Test(T obj){
        this->obj = obj;
    }

    void print(){
        cout << obj << endl;
    }
};

template<class objType>
class Test1{
private:
    objType obj;
public:
    Test1(objType obj){
        this->obj = obj;
    }

    void print(){
        cout << obj << endl;
    }
};

int main()
{
    Test<string,int> test1("Hello");    //specify types to classes
    test1.print();
    Test1<int> test2(1);
    test2.print();
    return 0;
}
