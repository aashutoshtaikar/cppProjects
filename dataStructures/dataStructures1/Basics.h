#pragma once
//call by value
int Internal_swap(int n1, int n2) {
	int temp = n1;
	n1 = n2;
	n2 = temp;
	return 0;
}

//call-by reference
int Refswap(int &n1, int &n2) {
	int temp = n1;
	n1 = n2;
	n2 = temp;
	return 0;
}

void PointerSwap(int *n1, int *n2) {
	int temp = *n1;
	*n1 = *n2;
	*n2 = temp;
}

//static variable : It ensures that the value is retained even after the function exits 
int StaticSwap(static int n1, static int n2) {
	static int temp = n1;
	n1 = n2;
	n2 = temp;
	return 0;
}

//int x = 1;
//int y = 2;
//cout << "x: " << x <<endl;
//cout << "y: " << y<< endl;
//
//Internal_swap(1,2);
//Refswap(x,y);
//PointerSwap(&x,&y);
//StaticSwap(x, y);
//
//cout << "x: " << x << endl;
//cout << "y: " << y << endl;

