#include<iostream>
#include<memory.h>
#include<map>
using namespace std;

/* 

 */

int romanToDec(string str){
    map<char,int> roman;
    roman['I']= 1;
    roman['V'] = 5;
    roman['X'] = 10;
    roman['L'] = 50;
    roman['C'] = 100;
    roman['D'] = 500;
    roman['M']= 1000;
    
    int num{0};
    int i = str.size() - 1;

    for(auto it2 = roman.find(str[str.size()-1]) ,  it1 = roman.find(str[str.size()-2]);  it1!=roman.begin(); ){
        if (it1->second > it2->second){
            num = it1->second + it2->second;
        }
        else{
            num = it2->second - it1->second;
        }
        it1--;
        it1--;
        it2--;
        it2--;
    }
    return num; 
}


int main(){
    cout << romanToDec("XVI") << endl;
}