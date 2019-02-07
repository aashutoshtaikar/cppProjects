#include<iostream>
#include<vector>
#include<string>
#include<cstring>

using namespace std;  

void bubbleSort(vector<int> &input);
void bubbleSort(int input[], int n);

void bubbleSort(vector<int> &input){
    int n = input.size(); 
    bool swapped = false;
    for(int i = 0; i < n-1; i++) // i counts the number of iterations till length - 1 as the first element is assumed to be sorted
    {
        for(int j = 0; j < n-1-i; j++)
        {
            if(input[j]>input[j+1]){
                int temp = input[j];
                input[j] = input[j+1];
                input[j+1] = temp;
                swapped = true;
            }
        }
         // IF no two elements were swapped by inner loop, then break 
        //if(!swapped) break; //usefull for efficiency //breaks the for loop
        if(!swapped) return; //exits the function
    }  
}

void bubbleSort(int input[], int n) {
	for (int i = 0; i < n - 1; i++) {
		// i represents how many elements 
		// have bubbled to correct place
		for (int j = 0; j + 1 < n - i; j++) {
			if (input[j] > input[j + 1]) {
				//swap
				int temp = input[j];
				input[j] = input[j + 1];
				input[j + 1] = temp;
			}
		}
	}
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