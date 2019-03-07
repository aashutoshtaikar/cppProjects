#include <iostream>

int main(int argc, char const *argv[])
{
    int *p1 = new int(5);
    //shallow copy -- copy the address of another ptr
    int *p2 = p1;

    //deep copy -- copy the value rather than the address of the pointer
    int *p3 = new int(*p1);

    return 0;
}
