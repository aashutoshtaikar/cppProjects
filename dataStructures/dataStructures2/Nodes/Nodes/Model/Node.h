#ifndef MODEL_NODE_H_
#define MODEL_NODE_H_


#include<iostream>

template<class Type>
class Node
{
private:
	Type value;		//What is stored in the Node
	Node *pointers; //reference to the array of nodes this is connected to
public:
	//constructors
	Node();
	Node(Type value);
	virtual ~Node(); //destructor

	//member functions
	Type getValue();
	void setValue(Type value);
	Node * getPointers();
};

#endif