//ArrayNode.h

#ifndef MODEL_ARRAYNODE_H_
#define MODEL_ARRAYNODE_H_

template<class Type>
class ArrayNode :public Node<Type>
{
private:
	ArrayNode * next;
public:
	ArrayNode();
	ArrayNode(Type value);
	ArrayNode(Type value, ArrayNode* next);
	virtual ~ArrayNode();

	ArrayNode * getNext();
	void setNext(ArrayNode * next);
};
#endif // !MODEL_ARRAYNODE_H_

