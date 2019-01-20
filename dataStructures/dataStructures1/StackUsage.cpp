#pragma once
#include<list>
#include<iterator>
#include<algorithm>
#include<iostream>
using namespace std;

class Stacks
{
public:
	void listofList() {
		list<int> l1{ 1,2,3,4 };
		list<int> l2{ 5,6,7,8 };
		list<int> temp;
		list<list<int>> ll;
		ll.push_back(l1);
		ll.push_back(l2);
	}

	//	//}
	//	temp.push_back(i);
	//	temp.push_back(2);
	//	ll.push_back(temp);

	//	list<list<int>>::iterator itr;
	//	for (itr = ll.begin(); itr != ll.end(); itr++) {
	//		list<int> tl = *itr;
	//		list<int>::iterator it;
	//		for (it = tl.begin(); it != tl.end(); it++) {
	//			cout << *it;
	//		}
	//		cout << endl << "end" << endl;
	//	}
	//}

	list<char> Stack;
	void ParenthesisCheck(char arr[]) {
		int arrSize = sizeof(arr) / sizeof(*arr);
		int i = 0;
		Stack.push_back('0');						//add a padded zero

		while (i <= arrSize - 1) {
			Stack.push_back(arr[i]);				//adds a new value from array input to the list
			
			list<char>::iterator itr1=Stack.end();	//example 
			itr1--;		
			itr1--;									//decrements the itr1 by 1
			auto itr2 = prev(Stack.end());			//auto keyword specifies that the type of the variable that is being declared will be automatically deducted from its initializer
													// automatic deduction of the data type of an expression

			list<char>::iterator itr3 = prev(prev(Stack.end())); //example of same operation as itr1
		/*	list<char>::iterator itr1 = Stack.end();
			itr1--;
			list<char>::iterator itr2 = Stack.end();
			list<char>::iterator itr = find(Stack.begin(), Stack.end(), 8); //returns the address of the 8th element
			auto it2 = std::next(Stack.begin());
		*/

			switch (*itr1)
			{
			case '{':
				if ('}' == *itr2) {
					Stack.pop_back();
					Stack.pop_back();

				}
				break;
			case '(':
				if (')' == *itr2) {
					Stack.pop_back();
					Stack.pop_back();

				}
				break;
			default:
				break;
			}
			i++;
		}

		Stack.pop_back();					//remove padded zero
		if (Stack.size() == 0) {
			cout << "Parenthesis Valid\n";
		}
		else {
			cout << "Invalid Parenthesis\n";
		}
	}
};

//Stacks ExampleStack;
////ExampleStack.listofList();
//
//char a[] = { '{','}','(',')' };
//char b[] = { '{','(',')','}' };
//char c[] = { '{','(','}',')' };
//ExampleStack.ParenthesisCheck(a);
//ExampleStack.ParenthesisCheck(b);
//ExampleStack.ParenthesisCheck(c);


