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
       
        
        ListNode* l3 = NULL;
        ListNode* prev_l3 = NULL;
        ListNode* head_l3 = NULL;
       
        //store to linked list
        int carry = 0;
        int tmp_val_l1 = 0;
        int tmp_val_l2 = 0;
        while(curr_l1!=NULL || curr_l2!=NULL){
            
            if(curr_l1!=NULL) tmp_val_l1 = curr_l1->val;
            else tmp_val_l1 = 0;
            if(curr_l2!=NULL) tmp_val_l2 = curr_l2->val;
            else tmp_val_l2 = 0;
            
            l3 = new ListNode( AddTo(tmp_val_l1, tmp_val_l2, carry) );
            if(prev_l3==NULL) head_l3 = l3; 
            if(prev_l3!=NULL) prev_l3->next = l3;
            prev_l3 = l3;
            
            if(curr_l1!=NULL) curr_l1 = curr_l1->next;
            if(curr_l2!=NULL) curr_l2 = curr_l2->next;
        } 
        
        if (carry!=0) carry_handler(l3, prev_l3, carry);
        
        return head_l3;
    }
    
    //carry handler after traversing both lists
    void carry_handler(ListNode* l3, ListNode* prev_l3, int& carry){
        string s_carry = to_string(carry);

        while(s_carry.size()!=0){
            //casting char to int; static_cast<int>(s_carry.back()) produces ascii which is unesirable ; boost lexical cast can be used OR the following method can be used
            l3 = new ListNode(s_carry.back() - '0');   
            if(prev_l3!=NULL) prev_l3->next = l3;
            prev_l3 = l3;   
            s_carry.pop_back();
        }
    }
    
    //adder module
    int AddTo(int from,int to,int& carry){
        int result = from + to + carry;
        
        //skim and store the carry and return units place
        string s_result = to_string(result);
        s_result.pop_back();
        if(s_result.size()>=1) {
            carry = std::stoi(s_result);
        }
        else{ 
            carry = 0;
        }
        
        return result%10; //units place
    }
    
};

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
