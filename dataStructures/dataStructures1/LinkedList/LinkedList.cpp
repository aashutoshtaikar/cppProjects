#include<stdio.h>
#include<iostream>

using namespace std;

class LinkedList {
private:
	struct node {
		int data;
		int Index; 
		node *next;
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
	void InsertNode(int pos,int addData);
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
	n->data = addData;
	n->Index = NULL;

	if (head != NULL) {					//if head is present
		curr = head;
		//temp = curr; //added
		while (curr->next != NULL) {	//traverse thru the end of the list
			//temp = curr;
			curr = curr->next;
		}
		curr->next = n;
		n->Index = curr->Index + 1; //added
	}
	else
	{
		head = n;						//if head is not present create it 
		head->Index = 0;				//index it to 0
	}
}

void LinkedList::InsertNode(int pos, int addData) {
	node* n = new node;
	n->data = addData;
	n->Index = pos;
	n->next = NULL;

	if (head != NULL) {
		curr = head;
		while (curr!=NULL && curr->Index != pos) {
			temp = curr;
			curr = curr->next;
		}
		temp->next = n;				//link prev node to newly inserted node 
		n->next = curr;

		for (curr = curr; curr != NULL; curr = curr->next) {
			curr->Index += 1;												//fix next node links
		}
	}
	else {
		head = n;
		head->Index = 0;
		head->data = addData;
	}
}

void LinkedList::DeleteNode(int delIndex) {
	node* delPtr = NULL;
	temp = head;
	curr = head;

	while (curr !=NULL && curr->Index !=delIndex )
	{
		temp = curr;
		curr = curr->next;
	}
	if (curr == NULL) {
		cout << delIndex << " was not in the list\n";
		delete delPtr;
	}
	else if (curr->next == NULL) {
		temp->next = NULL;
	}
	else {
		delPtr = curr;
		curr = curr->next;
		curr->Index = delPtr->Index;
		temp->next = curr;
		temp = temp->next;

		if (delPtr->Index == 0)  head = head->next;

		cout << "The value " << delPtr->data << " in Index " << delIndex ;
		delete delPtr;
		cout << " was deleted \n";

		for (curr = curr; curr != NULL;curr=curr->next) //fix other broken links
		{
			delPtr = curr;
			//curr = curr->next;
			curr->Index = delPtr->Index;
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


////Linked List--------------------------------------------
int main(int argc, char const *argv[])
{
	LinkedList ExampleList;

	ExampleList.AddNode(1);
	ExampleList.AddNode(2);
	ExampleList.AddNode(3);

	ExampleList.PrintList();
	ExampleList.DeleteNode(1);
	ExampleList.InsertNode(1, 5);
	ExampleList.PrintList();
	
	return 0;
}


