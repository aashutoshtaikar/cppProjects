#include <iostream>
#include <functional>
#include <future>
using namespace std;

/* implemenetation class and implemenetation functions */

class test
{
  public:
    int foo(int z)
    {
        cout << std::this_thread::get_id() <<" " << z << " child\n";
        return 0;
    }
};

int foo(int& numx){
    numx = 22;
    cout << std::this_thread::get_id() << numx << " child\n";
    return 0;
}

int bar(int *numx){
    *numx = 22;
    cout << std::this_thread::get_id() << *numx << " child\n";
    return 0;
}


int baz(test* testob){
    testob->foo(5);
}

void boo(){
    cout << "hello from boo\n";
}

/* running functions */

void future_childToParent(){
    int num = 10;
    std::future<int> fu = std::async(std::launch::async, foo, std::ref(num));
    int fuVar = fu.get();
    cout << num;
    auto s = std::bind(bar,&num);
    fu = std::async(std::launch::async,s);
    fuVar = fu.get();

    test testobj;
    std::future<int> bu = std::async(std::launch::async, baz, &testobj);
    int buVar = bu.get();
}

void future_wObj_childToParent(){
    test testobj;
    int y = 0;
    
    std::future<int> fu = std::async(std::launch::async, &test::foo, &testobj, 5);
    fu.get();
}

void future_wObj_ParentToChild(){
    test testobj;
    std::async(std::launch::async, &test::foo, &testobj, 5);
}

void void_future(){
    std::future<void> fu = std::async(std::launch::async, boo);
    fu.get();
}

void direct_async(){
    test testobj;
    std::async(std::launch::async, &test::foo, &testobj, 5);
    test* p_testobj;
    std::async(std::launch::async, &test::foo, p_testobj, 6);
}

int main(){
    cout <<  std::this_thread::get_id() << "\n";
    
    future_wObj_ParentToChild();
    // void_future();
}