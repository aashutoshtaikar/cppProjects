#include <iostream>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

#include "basics.cpp"
#include "BubbleSort.cpp"
#include "SelectionSort.cpp"
#include "MergeSorta.cpp"
#include "MergeSortb.cpp"
#include "quickSort.1.cpp"

int *generateArray(int size, int from, int to);
bool isSorted(int array[], int n);
bool isSortedDecreasing(int array[], int n);
void printArray(int array[], int n);

int run();

int *generateArray(int size, int from, int to)
{
	int *result = new int[size];
	for (int i = 0; i < size; i++)
	{
		result[i] = from + (rand() % static_cast<int>(to - from + 1));
	}
	return result;
}

bool isSorted(int array[], int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		if (array[i] > array[i + 1])
		{
			return false;
		}
	}
	return true;
}

bool isSortedDecreasing(int array[], int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		if (array[i] < array[i + 1])
		{
			return false;
		}
	}
	return true;
}

void printArray(int array[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << array[i] << ", ";
	}
	cout << endl;
}

int run()
{
	const int SIZE_OF_TESTING_ARRAY = 1000;
	const int NUMBER_OF_ARRAYS = 1000;
	const int RANGE_FROM = 1;
	const int RANGE_TO = 1000;

	const int NUMBER_OF_ALGORITHMS = 6; // Do not change unless you add another algorithm
	string functionNames[NUMBER_OF_ALGORITHMS] = {"Selection Sort", "Bubble Sort", "Optimalized Bubble Sort", "Merge Sort", "Quick Sort", "Median Quick Sort"};
	void (*functions[NUMBER_OF_ALGORITHMS])(int *, int) = {selectionSort, bubbleSort, bubbleSortOpt, mergeSortExecutor, quickSortExecutor, quickSortMedianExecutor};

	for (int i = 0; i < NUMBER_OF_ALGORITHMS; i++)
	{
		bool allSorted = true;
		clock_t begin = clock();

		for (int j = 0; j < NUMBER_OF_ARRAYS; j++)
		{
			int *inputArray = generateArray(SIZE_OF_TESTING_ARRAY, RANGE_FROM, RANGE_TO);
			int cloneArray[SIZE_OF_TESTING_ARRAY];
			memcpy(cloneArray, inputArray, 4 * sizeof(int)); // Copy all numbers from inputArray to cloneArray

			(functions[i])(inputArray, SIZE_OF_TESTING_ARRAY);
			if (!isSorted(inputArray, SIZE_OF_TESTING_ARRAY))
			{
				allSorted = false;
				cout << functionNames[i] << endl;
				cout << "ERROR this array is not sorted " << endl;
				//printArray(cloneArray, SIZE_OF_TESTING_ARRAY);
				cout << "Returned " << endl;
				//printArray(inputArray, SIZE_OF_TESTING_ARRAY);
			}
		}

		clock_t end = clock();
		double seconds = double(end - begin) / CLOCKS_PER_SEC;

		if (allSorted)
		{
			cout << "*******************************************" << endl;
			cout << "Finished " << NUMBER_OF_ARRAYS << " tests." << endl;
			cout << functionNames[i] << endl;
			cout << "Took : " << seconds << " seconds." << endl;
		}
	}

	/*
	Example of Simple call
	int input[10] = { 10,8,9,7,6,5,4,3,2,1 };
	mergeSortExecutor(input, 10);
	printArray(input, 10);
	*/

	return 0;
}

int main(int argc, char const *argv[])
{
	run();
	return 0;
}
