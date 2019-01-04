#include<iostream>
using namespace std;

class RecursionExamples
{
public:
	int factorialFind(int n) {
		if (n == 0 || n == 1) {
			return 1;
		}
		else
		{
			return n * factorialFind(n - 1);
		}
	}

	int powerOf(int Number, int n) {
		if (n == 1) {
			return 1;
		}
		else
		{
			return Number * powerOf(Number-1, n);
		}
	}

};


int main() {
	RecursionExamples Someobj;
	cout << Someobj.factorialFind(3);
	cout << Someobj.powerOf(3, 2);

	return 0;
}

