#pragma once

#ifndef _HEADER_H
#include "Header.h"
#endif

void selectionSort(vector<int> &input);
void selectionSort(int input[], int n);

void selectionSort(vector<int> &input){
    //i points at first number behind the wall
    //i goes till the second last number in a vector
    int n = input.size();
    for(int i = 0; i < n-1; i++)
    {
        int IndexofSmallest = i;
        //j goes till the last number in the vector after the wall
        for(int j = i+1; j < n; j++)
        {
            if(input[j]<input[IndexofSmallest]){
                IndexofSmallest = j;
            }
        }
        int temp = input[i];
        input[i] = input[IndexofSmallest];
        input[IndexofSmallest] = temp; 
    }
}

//--------------------------------------------------------------------------------

void selectionSort(int input[], int n) { 
	// n is length of our array
	for (int i = 0; i < n - 1; i++) {
		// i points at first number behind "wall"
		int indexOfSmallest = i;
		for (int j = i + 1; j < n; j++) {
			if (input[j] < input[indexOfSmallest]) {
				indexOfSmallest = j;
			}
		}
		// swap
		int temp = input[i];
		input[i] = input[indexOfSmallest];
		input[indexOfSmallest] = temp;
	}
}