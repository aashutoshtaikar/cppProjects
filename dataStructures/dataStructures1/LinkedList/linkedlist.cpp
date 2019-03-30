#include<iostream>
#include <exception>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

/* implicitly Indexed linked list */
class LinkedList {
private:
	typedef struct _node {
		int data;
		struct _node* next;
	}node;
	
	node* head; 

public:
	LinkedList(); 
	LinkedList(const int data);

	void add(const int data);
	void insert_at(const uint index, const int data);
	void remove(const int data);
	void remove_at(const uint index);
	void print();
};

LinkedList::LinkedList() {
	head = NULL;
}

LinkedList::LinkedList(const int data) {
	this->add(data);
}

void LinkedList::remove(const int data) {
	node* delPtr = NULL;
	node* temp = head;
	node* curr = head;

	while (curr != NULL && curr->data != data)
	{
		temp = curr;
		curr = curr->next;
	}
	if (curr == NULL) {
		cout << data << " was not in the list\n";
	}
	else if(curr->data==data) {
		delPtr = curr;
		curr = curr->next;
		temp->next = curr;
		delete delPtr;
		cout << "The value " << data << " was deleted\n";
	}
}


void LinkedList::add(const int data) {
	node *n = new node;
	n->next = NULL;
	n->data = data;
	
	node* curr = NULL;

	if (head != NULL) {					//if head is present
		curr = head;
		while (curr->next != NULL) {	//traverse thru the end of the list
			curr = curr->next;
		}
		curr->next = n;
	}
	else
	{
		head = n;						//if head is not present create it 
	}
}

void LinkedList::insert_at(const uint index,const int data) {
	node* n = new node;
	n->data = data;
	n->next = NULL;

	int count = index;

	node* temp = NULL;
	node* curr = head;

	if (head == NULL){
		head = n;
		head->data = data;
		return;
	}

		while (curr!=NULL && count != 0){
			temp = curr;
			curr = curr->next;
			count--;
			if(count!=0 && curr==NULL){
				cout << "index "<<  index << " out of list range\n";
				return;
			}
		}
		if(temp!=NULL) temp->next = n; //link prev node to newly inserted node
		else head = n;
		n->next = curr;	

	return;
}

void LinkedList::remove_at(const uint index) {
	node* delPtr = NULL;
	node* temp = head;
	node* curr = head;

	int indx = index;

	while (curr!=NULL && indx!=0){
		temp = curr;
		curr = curr->next;
		indx--;
	}
	if(curr==NULL){
		return;
	}
	else if(index == 0){
		temp = head;
		head = head->next;
		delete temp;
	}
	else {
		delPtr = curr;
		curr = curr->next;

		temp->next = curr;
		temp = temp->next;

		cout << "The value " << delPtr->data << " in Index " << index ;
		delete delPtr;
		cout << " was deleted \n";
	}
}

void LinkedList::print() {
	node* curr = head;

	while (curr != NULL) {
		cout << curr->data << ", ";
		curr = curr->next;
	}
	cout << "\n";
}




int main(int argc, char const *argv[])
{
	LinkedList ExampleList;

	ExampleList.add(1);
	ExampleList.add(2);
	ExampleList.add(3);
	ExampleList.print();
	
	// ExampleList.remove_at(1);
	// ExampleList.print();
	
	// ExampleList.insert_at(1, 5);
	// ExampleList.print();
	
	// ExampleList.remove(3);
	// ExampleList.print();

	// ExampleList.insert_at(0,3);
	// ExampleList.print();

	ExampleList.remove_at(0);
	ExampleList.print();
	return 0;
}


