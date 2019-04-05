#include <iostream>
#include<thread>
#include"test.cpp"
using namespace std;



int main()
{
    thread threadx(foo);
    threadx.join();

    //cout << "Hello World!" << endl;
    return 0;
}
