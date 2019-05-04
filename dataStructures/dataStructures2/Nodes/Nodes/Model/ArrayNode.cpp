#include"ArrayNode.h"

template<class Type>
ArrayNode<Type>::ArrayNode() :Node<Type>()
{
	this->next = nullptr;
}

template<class Type>
ArrayNode<Type>::ArrayNode(Type value) : Node<Type>(value)
{
	this->next = nullptr;
	this->value = value;
}

template<class Type>
ArrayNode<Type>::~ArrayNode()
{
	//TODO 
}

template<class Type>
ArrayNode<Type> * ArrayNode<Type> ::getNext()
{
	return this->next;
}

template<class Type>
void ArrayNode<Type>::setNext(ArrayNode* next)
{
	this->next = next;
}

