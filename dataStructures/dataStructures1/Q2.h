#include <iostream>
#include<string>
#include<vector>
#include<fstream>
#include<algorithm>
#include<functional>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);


#include<vector>
/*
 * Complete the 'customSort' function below.
 *
 * The function accepts INTEGER_ARRAY arr as parameter.
 */

void customSort(vector<int> arr) {
	list<int> l1;
	list<int> l2;
	list<list<int>> ll;

	arr.sort();

	for (int i = 0; i < arr.size(); i++) {
		int cnt = 0;
		l1.push_back(i);
		for (int j = 0; j < arr.size(); j++) {
			if (arr[i] == arr[j]) {
				cnt++;
				l2.push_back(cnt);
			}
		}
		ll.push_back(l1);
		ll.push_back(l2);
	}


}

