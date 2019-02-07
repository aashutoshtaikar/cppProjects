#include<iostream>
#include<vector>
#include<string>
#include<cstring>
#include "SelectionSort.cpp"

using namespace std;  
//for complexity = O(n log n) pick the pivot as a median

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

