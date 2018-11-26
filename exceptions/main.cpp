#include<iostream>
#include<vector>

using namespace std;

int division(int a, int b) {
	swap(a, b);
	if (b == 0) {
		throw "Division by 0 not possible";
	}
	return a / b;
	
}

static string arr(vector<int> arr,int k) {
	vector<int>::iterator x;
	for(x)
}

int main() {
	try {
		division(2, 0);
	}
	catch (const char* e) {
		cerr << e << endl;
	}
	system("pause");
}