#include <iostream>
using namespace std;

class Test
{
  private:
    int x{1};
    int y{2};

  public:
  void run();
  void run1();
  void run2();
};

void Test::run(){
    int a{1};
    int b{2};

    auto func = [=]() {
        cout << "Before:-" << "a:" << a << "  " << "b:" << b << endl;
        // a = 3; //cannot run this
        // b = 4;
    };

    func();

    cout << "after:-" << "a:" << a << "  " << "b:" << b << endl;
}

void Test::run1(){
    int a = 1;
    int b = 2;

    auto func = [&]() {
        cout << "Before:-" << "a:" << a << "  " << "b:" << b << endl;
         a = 3; //can run this as everything is passed by reference
         b = 4;
    };

    func();

    cout << "after:-" << "a:" << a << "  " << "b:" << b << endl;
}

void Test::run2(){
    int a = 1;
    int b = 2;
    //capturing this
    auto func = [this,&a]() {
        cout << "Before:-" << "x:" << x << "  " << "y:" << y << endl;
        cout << "Before:-" << "a:" << a << endl;
        x = 0; y = 0;   //this is already passed by reference 
        a = 0; //can do this only if passed by reference
    };

    func();

    cout << "after:-" << "x:" << x << "  " << "y:" << y << endl;
    cout << "after:-" << "a:" << a << endl;
}

int main(){
    Test test1;
    test1.run();
    cout << "---------" << endl;
    test1.run1();
    cout << "---------" << endl;
    test1.run2();

    return 0;
}