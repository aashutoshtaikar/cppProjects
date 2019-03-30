#include <iostream>
#include <functional>
using namespace std;

typedef function<void(int)> myfunc_t;
 
void run(myfunc_t myfunc){
    cout << "running myfunc\n";
    myfunc(1);
}

void print(int num){
    cout << num << "\n";
}

int main(){
    run(print);
    run(bind(print,3)); //overwrite args
}