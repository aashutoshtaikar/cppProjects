#include<vector>
#include<iostream>
class Arrays {
public:
	char *a;
	
	void CreateDynArray(int n) {	
		a = new char[n];				// allocate n bits and save ptr in a
		for (int i = 0; i <= n; i++) {
			a[i] = 0;					//initialize all array elements to 0
		}
	}

	//adds adder value to all the elements from left to right position
	//usage: create an object of class Arrays and then access this member function 
	//eg: x.customArrayAdd(arrayinput,0,4,2)
	void customArrayAdd(int *arr, int left, int right, int adder) {
		for (int i = left; i < right; i++) {
			for (int j = 0; j <= left; j++) {
				arr++;
			}
			*arr += adder;
		}

	}
};

vector<int> reverseArray(vector<int> a) {
	for (int i = 0, j = a.size() - 1; i < a.size() / 2 && j >= 0; i++, j--) {
		int x = a[j];
		a[j] = a[i];
		a[i] = x;
	}
	return a;
}

////arrays----------------------------------------------------

//int inputArr[] = { 1,1,1,4,5,6 };
//Arrays test;
//
//test.customArrayAdd(inputArr, 0, 4, 2);
//
//for (int i = 0; i < (sizeof(inputArr)/sizeof(*inputArr)); i++) {
//	cout << inputArr[i] << endl;
//