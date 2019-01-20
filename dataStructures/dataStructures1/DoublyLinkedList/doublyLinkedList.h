#pragma once
/* Doubly Linked list:
|prev|data|Index|next|<---->|prev|data|Index|next|<---->|prev|data|Index|next|<---->|prev|data|Index|next|
*/
#include<stdio.h>
#include<iostream>

using namespace std;

class LinkedList {
private:
	struct node {
		int data;
		int Index;
		node *next;
		node *prev;
	};
	//OR
	/*typedef struct node {
		int data;
		node *next;
	}*nodePtr;
	*/

	node *head;
	//OR
	//nodePtr head;

	node *curr;
	node *temp;

public:
	//prototyping
	LinkedList(); //constructor prototyping
	void AddNodeData(int addData);
	void DeleteNodeData(int delData);

	void AddNode(int addData);
	void InsertNode(int pos, int addData);
	void DeleteNode(int delIndex);
	void PrintList();
};

//typedef struct node* nodePtr; //creates a node pointer


LinkedList::LinkedList() {
	head = NULL;
	curr = NULL;
	temp = NULL;
}

//for data
void LinkedList::AddNodeData(int addData) {
	node *n = new node;
	n->next = NULL;
	n->prev = NULL;
	n->data = addData;
	
	if (head != NULL) {
		curr = head;
		while (curr->next != NULL) {
			curr = curr->next;
			curr->Index += 1;
		}
		curr->next = n;
	}
	else
	{
		head = n;
		head->Index = 0;
	}
}

void LinkedList::DeleteNodeData(int delData) {
	node* delPtr = NULL;
	temp = head;
	curr = head;

	while (curr != NULL && curr->data != delData)
	{
		temp = curr;
		curr = curr->next;
	}

	if (curr == NULL) {
		cout << delData << " was not in the list\n";
		delete delPtr;
	}
	else {
		delPtr = curr;
		curr = curr->next;
		temp->next = curr;
		delete delPtr;
		cout << "The value " << delData << "was deleted\n";
	}
}

void LinkedList::AddNode(int addData) {
	node *n = new node;
	n->next = NULL;
	n->prev = NULL;
	n->data = addData;
	n->Index = NULL;

	if (head != NULL) {					//if head is present
		curr = head;
		while (curr->next != NULL) {	//traverse thru the end of the list
			curr = curr->next;
		}
		curr->next = n;
		n->Index = curr->Index + 1;		//added
		n->prev = curr;
	}
	else{
		head = n;						//if head is not present create it 
		head->Index = 0;				//index it to 0
	}
}

void LinkedList::InsertNode(int pos, int addData) {
	node* n = new node;
	n->data = addData;
	n->Index = pos;
	n->next = NULL;
	n->prev = NULL;

	if (head != NULL) {
		curr = head;
		while (curr != NULL && curr->Index != pos) {
			temp = curr;
			curr = curr->next;
		}
		temp->next = n;				//link prev node to newly inserted node 
		n->next = curr;
		n->prev = temp;
		curr->prev = n;

		for (curr = curr; curr != NULL; curr = curr->next) {
			curr->Index += 1;												//fix next node indices
		}
	}
	else {
		head = n;
		head->Index = 0;
		head->data = addData;
		head->prev = NULL;
	}
}

void LinkedList::DeleteNode(int delIndex) {
	node* delPtr = NULL;
	temp = head;
	curr = head;

	while (curr != NULL && curr->Index != delIndex){ // curr node shouldn't be the last node and Index should match with delIndex
		temp = curr;
		curr = curr->next;
	}

	if (curr == NULL) {
		cout << delIndex << " was not in the list\n";
		delete delPtr;
	}
	else if (curr->next == NULL) {					//if curr node is last node
		temp->next = NULL;
	}
	else {
		delPtr = curr;
		curr = curr->next;
		curr->Index = delPtr->Index;
		temp->next = curr;
		curr->prev = temp;
		temp = temp->next;			//not necessary but done to maintain consistency 

		if (delPtr->Index == 0) {
			head = head->next;
			head->prev = NULL;
		}

		cout << "The value " << delPtr->data << " in Index " << delIndex;
		delete delPtr;
		cout << " was deleted \n";

		while (curr != NULL) //fix other broken node indices
		{
			temp = curr;
			curr = curr->next;
			if (curr == NULL) {
				return;
			}
			curr->Index = temp->Index + 1;
		}
	}
}

void LinkedList::PrintList() {
	curr = head;
	while (curr != NULL) {
		cout << curr->data << endl;
		curr = curr->next;
	}
}   