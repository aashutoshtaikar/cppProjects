#include "NodeController.h"


NodeController::NodeController()
{
	stringNode.setValue("hello how are you?");
	intNode.setValue(999);

	stringArrayNode.setValue("hey there!!");
	otherArrayNode.setValue("linked node");
	stringArrayNode.setNext(&otherArrayNode);
}



void NodeController::start()
{
	std::cout << "the contents of  in string node is :" << stringNode.getValue() << "\n";
	std::cout << "the value in the stringarray node is :" << stringArrayNode.getValue() << "\n";
	std::cout << "the linked node is :" << (*stringArrayNode.getNext()).getValue() << "\n";
}

NodeController::~NodeController() {}
