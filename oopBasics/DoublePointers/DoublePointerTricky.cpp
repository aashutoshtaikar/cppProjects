#include<iostream>

using namespace std;

int main(int argc, char const *argv[]){
    const char *p = "12345";
    p = "1224";
    cout << "ss";
    const char **q = &p; //double pointer(dp) q points to address of pointer 
    *q = "abcde";          //dereferencing (dp) q assigns the string to the 
    const char *s = ++p;
    p="XYZWVU";
    cout << *++s;


    return 0;
}
