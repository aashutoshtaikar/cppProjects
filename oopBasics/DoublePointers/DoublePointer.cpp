#include <iostream> 
using namespace std; 

void runPtrAddrSwap(){
    int c = 1;
    int d = 2; 

    int *a = &c;
    int *b = &d;

    //changes the address of pointers 
    cout << " Before a: " << a << " b: " << b << endl; 
    a = b;
    cout << " After a: " << a << " b: " << b << endl;
}



void changebyDeref(int *x, int *y){
    //changes the values held by pointers but not the address
    cout << " Before *x: " << *x << " *y: " << *y << endl;
    cout << "Before x: " << x << " y: " << y << endl; 
    *x = *y;
    cout << "change wo Deref x: " << x << " y: " << y << endl; 
    cout << " change by Deref *x: " << *x << " *y: " << *y << endl;
}

void runchangebyDeref(){
    int c = 1;
    int d = 2; 

    int *a = &c;
    int *b = &d;

    changebyDeref(a,b);
    cout << " change by Deref *a: " << *a << " *b: " << *b << endl;
}


void changewoDeref(int *x, int *y){
    //
    cout << "Before x: " << x << " y: " << y << endl; 
    x = y;
    cout << "change wo Deref x: " << x << " y: " << y << endl; 
}

void runchangewoDeref(){
    int c = 1;
    int d = 2; 

    int *a = &c;
    int *b = &d;
    int**pp = &a;

    changewoDeref(a,b);
    cout << "change wo Deref a: " << a << " b: " << b << endl;

}

void doublePtrchange(int **x, int *y){
    cout << " Before **x: " << **x << endl;
    cout << " Before *x: " << *x << " *y: " << *y << endl; 
    cout << " Before x: " << x << " y: " << y << endl; 
    *x = y;
    cout << " double Ptr change **x: " << **x << endl;
    cout << " double Ptr change *x: " << *x << " *y: " << *y << endl; 
    cout << " double Ptr change x: " << **x << " y: " << y << endl; 
}


void rundoublePtrchange(){
    int c = 1;
    int d = 2; 

    int *a = &c;
    int *b = &d;
    int**pp = &a;

    doublePtrchange(pp,b);
    cout << "after function complete -----------" << endl;
    cout << " double Ptr change a: " << a << " b: " << b << endl; 
    cout << " double Ptr change *a: " << *a << " *b: " << *b << endl;
    cout << " double Ptr change *pp: " << *pp << endl; 
    cout << " double Ptr change **pp: " << **pp << endl; 
}

int main(){
    runPtrAddrSwap(); 
     cout << "---------------" << endl;
    runchangebyDeref();
     cout << "---------------" << endl;
    runchangewoDeref();
     cout << "---------------" << endl;
    rundoublePtrchange();
}