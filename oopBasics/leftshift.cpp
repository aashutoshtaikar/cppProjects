#include<iostream>
#include<functional>
using namespace std;

#define FOO_FLAG (1 << 0)
#define BAR_FLAG (1 << 1)
#define BAZ_FLAG (1 << 2)

function<int(int)> logicfunct = [](int x){ 
    return x;
    };

int main(){
    int ret = logicfunct(FOO_FLAG | BAR_FLAG & BAZ_FLAG);
    cout << ret << endl;
    return 0;
}