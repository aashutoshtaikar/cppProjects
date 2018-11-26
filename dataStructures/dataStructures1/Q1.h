#pragma once
#include <iostream>
#include<string>
#include<vector>
#include<fstream>
#include<algorithm>
#include<functional>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);



/*
 * Complete the 'alternatingParityPermutations' function below.
 *
 * The function is expected to return a 2D_INTEGER_ARRAY.
 * The function accepts INTEGER n as parameter.
 */

vector<vector<int>> alternatingParityPermutations(int n) {

}

int willBeMain()
{
	ofstream fout(getenv("OUTPUT_PATH"));

	string n_temp;
	getline(cin, n_temp);

	int n = stoi(ltrim(rtrim(n_temp)));

	vector<vector<int>> result = alternatingParityPermutations(n);

	for (int i = 0; i < result.size(); i++) {
		for (int j = 0; j < result[i].size(); j++) {
			fout << result[i][j];

			if (j != result[i].size() - 1) {
				fout << " ";
			}
		}

		if (i != result.size() - 1) {
			fout << "\n";
		}
	}

	fout << "\n";

	fout.close();

	return 0;
}

string ltrim(const string &str) {
	string s(str);

	s.erase(
		s.begin(),
		find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
	);

	return s;
}

string rtrim(const string &str) {
	string s(str);

	s.erase(
		find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
		s.end()
	);

	return s;
}