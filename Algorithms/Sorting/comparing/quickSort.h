#pragma once 
/* bad practice to do this but done for simplicity and readability over here */
#ifndef _HEADER_H
#include "Header.h"
#endif

#include "SelectionSort.h"

int parTn(vector<int> input, int from, int to);
void quickSort(vector<int> input, int from, int to);

int parTn(vector<int> input, int from, int to){
    int pivot = input[to];      //choosing pivot as the end O(n^2)
    int wall = from;
    for(int i = from; i < to; i++){
        if(input[i]<=pivot){        
            int temp = input[wall];
            input[wall] = input[i];
            input[i] = temp;
            wall++;                 //increment wall 
        }
        //else if elements<pivot continue incrementing i and not incrementing wall
    }
    //swap the pivot to the wall position
    input[to]=input[wall];
    input[wall]=pivot;
    return wall;
}

void quickSort(vector<int> input, int from, int to){
    if (from<to) {
        int indexOfPivot = parTn(input, from, to);
        quickSort(input, from, indexOfPivot - 1);
        quickSort(input, indexOfPivot+1 , to);
    } 
}



//for complexity = O(n log n) pick the pivot as a median

int medianOfThree(vector<int> input, int first, int middle, int last){
    int array[] = {input[first],input[middle],input[last]};
    selectionSort(input);
    if (array[1]==input[first]) {
        return first;
    }
    else if(array[1]==input[middle]){
        return middle;
    }
    else{
        return last;
    }
    //returns the index of the median(This is done for changing from's and to's in a recursive call)
}

int parTnMedian(vector<int> input, int from, int to){
    int indexOfPivot = medianOfThree(input, from, (from+to)/2, to);
    int pivot = input[indexOfPivot];      //choosing pivot as the end O(n^2)
    
    int wall = from;
    for(int i = from; i < to; i++){
        if(input[i]<=pivot){        
            int temp = input[wall];
            input[wall] = input[i];
            input[i] = temp;
            wall++;                 //increment wall 
        }
        //else if elements<pivot continue incrementing i and not incrementing wall
    }
    //swap the pivot to the wall position
    input[to]=input[wall];
    input[wall]=pivot;
    return wall;
}

//QuickSort for arrays---------------------------------------------------------------------------------

int partition(int input[], int from, int to) {
	int pivot = input[to];
	int wall = from;
	for (int i = from; i < to; i++) {
		if (input[i] <= pivot) {
			int temp = input[wall];
			input[wall] = input[i];
			input[i] = temp;
			wall++;
		}
	}
	input[to] = input[wall];
	input[wall] = pivot;

	return wall;
}

void quickSort(int input[], int from, int to) {
	if (from < to) {
		int indexOfPivot = partition(input, from, to);
		quickSort(input, from, indexOfPivot - 1);
		quickSort(input, indexOfPivot + 1, to);
	}
}

// this function can be used for "quickSort call" where you only pass array
// it generates "from" and "to" parameters
void quickSortExecutor(int input[], int n) {
	quickSort(input, 0, n - 1);
}

void bubbleSortOpt(int input[], int n) {
	for (int i = 0; i < n - 1; i++) {
		// i represents how many elements have bubbled to correct place
		bool swapped = false;
		for (int j = 0; j + 1 < n - i; j++) {
			if (input[j] > input[j + 1]) {
				//swap
				swapped = true;
				int temp = input[j];
				input[j] = input[j + 1];
				input[j + 1] = temp;
			}
		}
		if (!swapped) {
			return;
		}
	}
}

int medianOfThree(int input[], int first, int middle, int last) {
	int array[] = { input[first], input[middle], input[last] };
	selectionSort(array, 3);
	if (array[1] == input[first]) {
		return first;
	}
	else if (array[1] == input[middle]) {
		return middle;
	}
	else {
		return last;
	}
}

int partitionMedian(int input[], int from, int to) {
	int indexOfPivot = medianOfThree(input, from, (from + to) / 2, to);
	int pivot = input[indexOfPivot];
	if (indexOfPivot != to) {
		input[indexOfPivot] = input[to];
	}
	int wall = from;
	for (int i = from; i < to; i++) {
		if (input[i] <= pivot) {
			int temp = input[wall];
			input[wall] = input[i];
			input[i] = temp;
			wall++;
		}
	}
	input[to] = input[wall];
	input[wall] = pivot;

	return wall;
}
void quickSortMedian(int input[], int from, int to) {
	if (from < to) {
		int indexOfPivot = partitionMedian(input, from, to);
		quickSortMedian(input, from, indexOfPivot - 1);
		quickSortMedian(input, indexOfPivot + 1, to);
	}
}

// this function can be used for "quickSortAverage call" where you only pass array
// it generates "from" and "to" parameters
void quickSortMedianExecutor(int input[], int n) {
	quickSortMedian(input, 0, n - 1);
}