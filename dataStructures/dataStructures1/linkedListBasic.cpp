/* linked list struct example */
#include<stdio.h>
#include<iostream>
using namespace std;

 struct node {
	 int data;
	 node *next;
 };

 node* n;
 node* t;
 node* h;

 int main() {
	 n = new node;
	 n->data = 1;
	 t = n;
	 h = n;

	 n = new node;
	 n->data = 2;
	 t->next = n;
	 t = t->next;

	 n = new node;
	 n->data = 3;
	 t->next = n;
	 t = t->next;

	 n = new node;
	 n->data = 4;
	 t->next = n;
	 n->next = NULL;

	 n = h;
	 while (n != NULL)
	 {
		 cout << n->data << endl;
		 n = n->next;
	 }

     return 0;
 }
