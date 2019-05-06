//ArrayNode.h

#ifndef MODEL_ARRAYNODE_H_
#define MODEL_ARRAYNODE_H_

template<class Type>
class ArrayNode :public Node<Type>
{
private:
	ArrayNode* next;

public:
	ArrayNode():Node<Type>(){}

	template<class Type>
	ArrayNode(Type value) : Node<Type>(value){
		this->next = nullptr;
	}

	virtual ~ArrayNode(){
		//TODO 
	}

	ArrayNode* getNext(){
		return this->next;
	}

	void setNext(ArrayNode* next){
		this->next = next;
	}

};
#endif // !MODEL_ARRAYNODE_H_

