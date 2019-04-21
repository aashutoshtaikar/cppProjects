#include <iostream>
#include <vector>
#include <list>
const char* testfunction(int x){
    std::cout << x << "\n";
    return "test";
}

// typedef const char*(*someptr)(int); //inconvenient 
using someptr = const char*(*)(int);    // convenient

void somefunc(someptr pfunc, int x, int y){
    pfunc(x+y); //callback
}

template<class T>
using Names = std::vector< std::list<T> >; 

void test_names(){
    Names<std::string> name;
    name.push_back({"hello", "test"});
    std::list<std::string> l1 = name.back();
    for (auto &&i : l1)
    {
        std::cout << i << " ";
    }
    //name.back();
}

int main() {
    // somefunc(testfunction,1,2);
    // test_names();
    
   return 0;
}