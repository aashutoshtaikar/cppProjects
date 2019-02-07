#include <iostream>
#include <thread>
using namespace std;

void foo(){
    cout <<"hello\n";
}

int main()
{
    std::thread thread1(foo);
    thread1.join();
    cout << "Hello World!" << endl;
    return 0;
}
