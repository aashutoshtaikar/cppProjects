#include <iostream> 
using namespace std; 


void changebyDeref(int *x, int *y){
    cout << " Before *x: " << *x << " *y: " << *y << endl; 
    *x = *y;
    cout << " change by Deref *x: " << *x << " *y: " << *y << endl;
}

void changewoDeref(int *x, int *y){
    cout << "Before x: " << x << " y: " << y << endl; 
    x = y;
    cout << "change wo Deref x: " << x << " y: " << y << endl; 
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



int main(){
    int c = 1;
    int d = 2; 

    int *a = &c;
    int *b = &d;
    int**pp = &a;
    
    // changebyDeref(a,b);
    // cout << " change by Deref *a: " << *a << " *b: " << *b << endl;
    
    // changewoDeref(a,b);
    // cout << "change wo Deref a: " << a << " b: " << b << endl;

    doublePtrchange(pp,b);
    cout << "funct runnning -----------" << endl;
    cout << " double Ptr change a: " << a << " b: " << b << endl; 
    cout << " double Ptr change *a: " << *a << " *b: " << *b << endl;
    cout << " double Ptr change *pp: " << *pp << endl; 
     cout << " double Ptr change **pp: " << **pp << endl; 

    // cout << "*a: " << *a << " *b: " << *b << endl; 
    // a = b;
    // cout << "*a: " << *a << " *b: " << *b << endl;

    // cant_change(a,f);

    // cout << "*a: " << *a << endl;

    // change(pp,f);

    //  cout << "*a: " << *a << endl;

    // other_change(a,f);
    // cout << "a: " << a << " f: " << f << endl;
    // cout << "*a: " << *a << " *f: " << *f << endl;


}