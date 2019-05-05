#ifndef CONTROLLER_NODECONTROLLER_H_
#define CONTROLLER_NODECONTROLLER_H_

#include"../Model/Node.h"
#include"../Model/ArrayNode.h"
#include<string>


class NodeController
{
private:
	Node<std::string> stringNode;
	Node<int> intNode;
	ArrayNode<std::string> stringArrayNode;
	ArrayNode<std::string> otherArrayNode;
public:
	NodeController();
	virtual ~NodeController();
	void start();
};

#endif // !CONTROLLER_NODECONTROLLER_H_

