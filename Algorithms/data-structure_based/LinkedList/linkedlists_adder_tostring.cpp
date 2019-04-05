/* 
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example:

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
Explanation: 342 + 465 = 807.

https://leetcode.com/problems/add-two-numbers/

 */
#include <iostream>
#include <string>
#include <boost/lexical_cast.hpp>
using namespace std;
using boost::lexical_cast;


 //Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* curr_l1 = l1;
        ListNode* curr_l2 = l2;
        std::string s_l1, s_l2 = {};
        
        ListNode* l3 = NULL;
        ListNode* prev_l3 = NULL;
        ListNode* head_l3 = NULL;
        //extraction
        while(curr_l1!=NULL ){
            s_l1.insert(0,1,to_char(curr_l1->val));
            curr_l1 = curr_l1->next;
           
        }
        
        while(curr_l2!=NULL){
            s_l2.insert(0,1,to_char(curr_l2->val)); 
             curr_l2 = curr_l2->next;
        }
        
        //addition
       // cout << s_l1 << " " << s_l2 << "\n";
        long long result = 0;
        try{
            result = std::stoll(s_l1) + std::stoll(s_l2);
        }
        catch(std::exception& e){
            std::cout << "too long" << "\n";
        }
        //cout << result << "\n"; 
        std::string s_result = std::to_string(result);

        //store to linked list
        for(int i = s_result.size()-1 ; i>=0 ; i--){
            l3 = new ListNode(s_result[i] - '0');
            if(prev_l3==NULL) head_l3 = l3; 
            if(prev_l3!=NULL) prev_l3->next = l3;
            prev_l3 = l3;
        } 
        
        return head_l3;
    }
    
    char to_char(int val){
        string s = std::to_string(val);
        return s[0];
    }
};

void boost_lexical_cast_Example(){
    int x = 1;
    char somechar =  lexical_cast<char>(x) ;
    cout << somechar << "\n";
    string s;
    // s.insert(0,1,(char)x);
    s.insert(0,1,'y');
    s.insert(0,1,'z');
    cout << s;

}

void trimLeftTrailingSpaces(string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
        return !isspace(ch);
    }));
}

void trimRightTrailingSpaces(string &input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
        return !isspace(ch);
    }).base(), input.end());
}

vector<int> stringToIntegerVector(string input) {
    vector<int> output;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    stringstream ss;
    ss.str(input);
    string item;
    char delim = ',';
    while (getline(ss, item, delim)) {
        output.push_back(stoi(item));
    }
    return output;
}

ListNode* stringToListNode(string input) {
    // Generate list from the input
    vector<int> list = stringToIntegerVector(input);

    // Now convert that list into linked list
    ListNode* dummyRoot = new ListNode(0);
    ListNode* ptr = dummyRoot;
    for(int item : list) {
        ptr->next = new ListNode(item);
        ptr = ptr->next;
    }
    ptr = dummyRoot->next;
    delete dummyRoot;
    return ptr;
}

string listNodeToString(ListNode* node) {
    if (node == nullptr) {
        return "[]";
    }

    string result;
    while (node) {
        result += to_string(node->val) + ", ";
        node = node->next;
    }
    return "[" + result.substr(0, result.length() - 2) + "]";
}

int main() {
    string line;
    while (getline(cin, line)) {
        ListNode* l1 = stringToListNode(line);
        getline(cin, line);
        ListNode* l2 = stringToListNode(line);
        
        ListNode* ret = Solution().addTwoNumbers(l1, l2);

        string out = listNodeToString(ret);
        cout << out << endl;
    }
    return 0;
}

