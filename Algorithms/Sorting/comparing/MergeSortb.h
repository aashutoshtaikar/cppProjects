#pragma once
/* bad practice to do this but done for simplicity and readability over here */
#ifndef _HEADER_H
#include "Header.h"
#endif

void mergeSortb(vector<int> &numbers,int low, int high);
void mergeAllb(vector<int> &numbers,int low,int middle, int high);
void mergeSortbEx(vector<int> &numbers);


void mergeSortb(vector<int> &numbers,int low, int high){
    if (low<high) {
        int middle = low + (high - low) / 2;
        mergeSortb(numbers, low, middle);
        mergeSortb(numbers, middle+1, high);
        mergeAllb(numbers, low, middle, high);
    }
}

void mergeAllb(vector<int> &numbers, int low,int middle, int high){
    vector<int> helper;
    helper.resize(high-low);
    //copy both parts into helper array
    

    for(int i = low; i <= high; i++){
        helper[i] = numbers[i];
    }

    int i = low;
    int j = middle + 1;
    int k = low;
    
    while(i<=middle && j<=high){      
        if (helper[i]<=helper[j]) {
            numbers[k] = helper[i];
            i++;
        } else {
            numbers[k] = helper[j];
            j++;
        }
        k++;
    }

    while(i<=middle){
        numbers[k] = helper[i];
        k++;
        i++;
    }
    
}

void mergeSortbEx(vector<int> &numbers){
    mergeSortb(numbers,0,numbers.size()-1);
}

