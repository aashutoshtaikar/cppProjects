#ifndef CONTROLLER_NODECONTROLLER_H_
#define CONTROLLER_NODECONTROLLER_H_

#include"Node.h"
#include"Node.cpp"
#include"ArrayNode.h"
#include"ArrayNode.cpp"
#include<string>

using namespace std;

class NodeController
{
private:
	Node<string> stringNode;
	Node<int> intNode;
	ArrayNode<string> stringArrayNode;
	ArrayNode<string> otherArrayNode;
public:
	NodeController();
	virtual ~NodeController();
	void start();
};

#endif // !CONTROLLER_NODECONTROLLER_H_

