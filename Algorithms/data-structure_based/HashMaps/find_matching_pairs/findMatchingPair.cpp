/* question 1
    You are given a String, input, comprised of alphabetical letters with varying case.  
These letters should create pairs with one another, based on case.  For example, the letter 'A' forms a "matching pair" with the letter 'a', in that order.  

Rules:
The first letter must be upper-case.
Every upper-case letter must be followed by its lower-case version or any upper-case letter.
When an upper-case letter is followed by its lower-case version, those two letters are considered a "matching pair" and can then be disregarded from further match consideration.
If any of these rules are broken or a lower-case letter is encountered that does not create a "matching pair" with its nearest un-matched left neighbour, that letter and all following letters are considered "un-matched".
 
Output:
Your method should return the zero-based index of the last matching lower-case letter, or -1 if no pairs exist.  
Limits: 0 < input length < 10,000 characters
The optimal method has a running time of O(input length).

Sample input #1: ABba
Sample output #1: 3 

Sample input #2 : ABbCca
Sample output #2: 5

 */

#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int findMatchingPair(string input){
    unordered_map<char, int > mUpper;
    int index{};
    
    for(size_t i = 0; i < input.length(); i++){
        if(isupper(input[i])){
            mUpper[input[i]] = 0;   //if upper, make the count 0
        }
        else if (islower(input[i])){
            if(mUpper.find(toupper(input[i])) != mUpper.end() && mUpper.find(toupper(input[i]))->second ==0){
                mUpper[toupper(input[i])]++; //matched pair
                index = i;
            }
        }
    }

    return index;

}

int main(int argc, char const *argv[])
{
    cout << findMatchingPair("aBcDAbNBnb");
    return 0;
}
