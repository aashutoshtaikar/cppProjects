#pragma once

#ifndef _HEADER_H
#include "Header.h"
#endif

void ModArr(vector<int> &x);
void printVec(vector<int> &input);
int factorial(int n);
int factorialVisualization(int n);


void ModArr(vector<int> &x){        //square every element of the vector; pass by reference (vector)
    
    for(int i = 0; i < x.size(); i++)
    {
        x[i] = x[i]*x[i];
    }
    
}

void printVec(vector<int> &x){
    //.size() returns number of elements in a vector
    for(int i = 0; i < x.size(); i++)
    {
        cout << x[i]<<" ";
    }
    cout<<endl;
}

void printArr(int x[], int n){
    
    for(int i = 0; i < n; i++)
    {
        cout << x[i] << " ";
    }
    cout <<endl;
}

int factorial(int n){
    if (n==1) {
        return 1;
    }
    else{
        return n * factorial(n-1);
    }
}

int factorialVisualization(int n){
    cout<<"Computing" << n << endl;
    if (n==1){
        cout << "Result for "<< n << " is " << n << endl;
        return 1;
    } 
    else {
        int result= n * factorialVisualization(n-1);
        cout<<"Result for " << n << " is " << n * result << endl;
        return n * result;
    }
} 

