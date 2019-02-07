#include <iostream>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

void mergeSorta(vector<int> &input, int from, int to);
void mergeSortaEx(vector<int> &input, int n);
void mergeAlla(vector<int> &input, int from, int middle, int to);

void mergeSorta(vector<int> &input, int from, int to)
{
    if (from < to)
    {
        int middle = (from + to) / 2;
        mergeSorta(input, from, middle);
        mergeSorta(input, middle + 1, to);
        mergeAlla(input, from, middle, to);
    }
}

//mergeSort Executor
void mergeSortaEx(vector<int> &input)
{
    mergeSorta(input, 0, input.size() - 1);
}

void mergeAlla(vector<int> &input, int from, int middle, int to)
{
    int lengthLeft = middle - from + 1;
    int lengthRight = to - middle;
    int *left = new int[lengthLeft + 1];
    int *right = new int[lengthRight + 1];

    for (int i = 0; i < lengthLeft; i++)
    {
        left[i] = input[from + i];
    }

    for (int i = 0; i < lengthRight; i++)
    {
        right[i] = input[middle + 1 + i];
    }

    left[lengthLeft] = INT32_MAX;
    right[lengthRight] = INT32_MAX;

    int leftPointer = 0;
    int rightPointer = 0;

    for (int i = from; i <= to; i++)
    {
        if (left[leftPointer] > right[rightPointer])
        {
            input[i] = right[rightPointer];
            rightPointer++;
        }
        else
        {
            input[i] = left[leftPointer];
            leftPointer++;
        }
    }
}

//mergesort for Arrays ---------------------------------------------------------------------

void mergeSort(int input[], int from, int to);
void merge(int input[], int from, int middle, int to);
void mergeSortExecutor(int input[], int n);

void mergeSort(int input[], int from, int to)
{
    if (from < to)
    {
        int middle = (from + to) / 2;
        mergeSort(input, from, middle);
        mergeSort(input, middle + 1, to);
        merge(input, from, middle, to);
    }
}

void merge(int input[], int from, int middle, int to)
{
    int lengthLeft = middle - from + 1;
    int lengthRight = to - middle;
    int *left = new int[lengthLeft + 1];
    int *right = new int[lengthRight + 1];

    for (int i = 0; i < lengthLeft; i++)
    {
        left[i] = input[from + i];
    }
    for (int i = 0; i < lengthRight; i++)
    {
        right[i] = input[middle + i + 1];
    }
    left[lengthLeft] = __INT_MAX__;
    right[lengthRight] = __INT_MAX__;

    int leftPointer = 0;
    int rightPointer = 0;
    for (int i = from; i <= to; i++)
    {
        if (left[leftPointer] > right[rightPointer])
        {
            input[i] = right[rightPointer];
            rightPointer++;
        }
        else
        {
            input[i] = left[leftPointer];
            leftPointer++;
        }
    }
}

void mergeSortExecutor(int input[], int n)
{
    mergeSort(input, 0, n - 1);
}