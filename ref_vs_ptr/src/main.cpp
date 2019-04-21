#include <iostream>
#include <memory>
using namespace std;

/* Ref: address is bound and cannot be changed 
        cannot hold a nullptr
    Ptr: Not bound to one address can hold/own/point to a different address 
*/
void ref_vs_ptr(){
    int j = 1;
    cout <<"address of j:" << &j << "\n";
    int k = 2;
    cout <<"address of k:" << &k << "\n";
    
    int& i = j;
    i = k;

    cout <<"address of i:" << &i << ", value of i =" << i;
}

/* pointer to pointer */
void print_ptr(int** ptr){
    cout << "ptr address: " << &(*ptr) << ",  pointing to address: " << *ptr << ", value: "<< *(*ptr) <<"\n";
}

/* passing pointer by reference */
void print_ptr(int*& ptr){
    cout << "ptrs address: " << &ptr << ",  pointing to address: " << ptr << ", value: "<< *ptr <<"\n";
}

int& returns_ref(){
    int i = 10;
    return i;   //error: returning a stack de-allocated value by reference
}

int* returns_ptr(){
    int stackvar = 10;
    // int *x = &stackvar; //never do this
    int *x = new int(10);
    int *y = x;
    print_ptr(x);
    print_ptr(y);

    return x;
}

void test_returns_ptr_ptrRef(){
    int* x = returns_ptr();
    cout << "ptr address: " << &x << ",  pointing to address: " << x << ", value: "<< *x <<"\n";
    print_ptr(x);
}


void test_uniqueptr(){
    using std::cout;
    int *a = new int(2);
    int *b = new int(3);
    std::unique_ptr<int> p (a);
    cout << *p;
    // int *s = p.release();    //right way raw pointer needs to be managed/freed
    // std::unique_ptr<int> s = std::make_unique<int>(*p.release());   //wrong way of releasing a unique_ptr to another unique_ptr
    std::unique_ptr<int> s = static_cast<std::unique_ptr<int>>(p.release()); //releases the ownership to raw pointer 
    cout << *s;
    p.reset(b);
    cout << *p;

}

void test_delete(){
    int* i = new int(1);
    print_ptr(i);
    delete i; 
    i = nullptr;  //important to do this 

    // print_ptr(i);
    // i = new int(2);
    // print_ptr(i);
    // delete i;
}


int main() {
    // ref_vs_ptr();
    // cout << returns_ref();
    test_uniqueptr();


    return 0;    
}