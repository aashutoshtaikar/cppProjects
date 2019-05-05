#ifndef MODEL_NODE_H_
#define MODEL_NODE_H_

template<class Type>
class Node
{
private:
	Type value;		//What is stored in the Node
	Node* pointers; //reference to the array of nodes this is connected to

public:
	Node(){
		this->pointers = nullptr;
	}

	template<class Type>
	Node(Type value){
		this->value = value;
		this->pointers = nullptr;
	}

	~Node(){
		//to do
	}

	getValue(){
		return this->value;
	}

	template<class Type>
	setValue(Type value){
		this->value = value;
	}

	getPointers(){
		return this->pointers;
	}
};

#endif