#include<stdio.h>
#include<iostream>
#include<string>
#include<list>

using namespace std;

/* 
#pragma startup function1
#pragma exit function2

#pragma startup and #pragma exit: These directives helps us to specify the functions 
that are needed to run before program startup( before the control passes to main()) 
and just before program exit (just before the control returns from main()). 
*/

#define LIMIT 5         //define macro
#undef LIMIT            //undefine macro           
#define AREA(l,b) (l*b) //define macro with args, works similar to functions

//function prototypes not needed for __attribute__(())
void funct1() __attribute__((constructor)); 
void funct2() __attribute__((destructor)); 

void funct1(){
   printf("Inside func1()\n"); 
}

void funct2(){
   std::cout << "Inside func2()" <<std::endl; //using namespace std does not work here   
}

int main() {
    list<int> ilist1{5,6,7};
	initializer_list<int> ilist2{1,2,3};
    int area = AREA(2,3);
    cout << "Area: " << area << endl; 

	return 0;
}