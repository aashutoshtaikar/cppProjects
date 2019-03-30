#include<iostream>

using namespace std;

/* explicitly Indexed linked list */
class LinkedList {
private:
	typedef struct _node {
		int Index;
		int data;
		struct _node* next;
	}node;
	
	node* head; 

public:
	LinkedList(); 
	
	void add(int data);
	void insert_at(int index,int data);
	void remove(int data);
	void remove_at(int index);
	void print();
};


LinkedList::LinkedList() {
	head = NULL;
}

void LinkedList::remove(int data) {
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
	else {
		delPtr = curr;
		curr = curr->next;
		temp->next = curr;
		delete delPtr;
		cout << "The value " << data << "was deleted\n";
	}
}


void LinkedList::add(int data) {
	node *n = new node;
	n->next = NULL;
	n->data = data;
	n->Index = NULL;

	if (head != NULL) {					//if head is present
		node* curr = head;
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

void LinkedList::insert_at(int index, int data) {
	node* n = new node;
	n->data = data;
	n->Index = index;
	n->next = NULL;
	node* temp = NULL;
	node* curr = head;

	if (head != NULL) {
		while (curr!=NULL && curr->Index != index) {
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
		head->data = data;
	}
}

void LinkedList::remove_at(int index) {
	node* delPtr = NULL;
	node* temp = head;
	node* curr = head;

	while (curr !=NULL && curr->Index !=index ){
		temp = curr;
		curr = curr->next;
	}

	if (curr == NULL) {
		cout << index << " was not in the list\n";
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

		cout << "The value " << delPtr->data << " in Index " << index ;
		delete delPtr;
		cout << " was deleted \n";

		for (curr = curr; curr != NULL; curr=curr->next){ //fix indices of all nodes
			delPtr = curr;
			curr->Index = delPtr->Index;
		}
	}
}

void LinkedList::print() {
	node* curr = head;
	while (curr != NULL) {
		cout << curr->Index << "->";
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
	ExampleList.remove_at(1);
	ExampleList.print();
	ExampleList.insert_at(1, 5);
	ExampleList.print();
	
	return 0;
}


