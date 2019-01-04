
#include<iostream>
#include "doublyLinkedList.h"
#include"Stacks.h"
#include"Arrays.h"
#include"Tree.h"
#include<string>
#include"strings.h"
#include"Basics.h"
#include"hash.h"
using namespace std;


int main(){
	HashIt hashObj; //calls the constructor
	
	hashObj.AddItem("Aashutosh", "wine");
	hashObj.AddItem("Ganesh", "coffee");
	hashObj.AddItem("Ameya", "Tea");
	hashObj.AddItem("Sarah", "mocha");
	hashObj.AddItem("Mike", "latte");
	hashObj.AddItem("Emma", "locha");

	hashObj.PrintTable();
	hashObj.PrintItemsinIndex(4);
	//hashObj.findBucket("Aashutosh");
	//system("pause");
	
}


