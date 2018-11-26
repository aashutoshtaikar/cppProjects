#pragma once

#include<list>
using namespace std;

class Tree {
public:
	int number;
	list<Tree> children;


	Tree(int n, list<Tree> ns) {
		number = n;
		children = ns;
	}

	list<Tree> getChildren() {
		return children;
	}

	//static NestedInteger Leaf(int n) {
	//	return NestedInteger(n, list<NestedInteger> {});
	//}

	//static NestedInteger Node(int n, list<NestedInteger> ns) {
	//	return NestedInteger(n, ns);
	//}

	int getNum() {
		return number;
	}

};

//tree---------------------------------------------------
//list<Tree> t1 = list<Tree>{ Tree(2,list<Tree>{Tree(6,list<Tree>{})}), Tree(1,list<Tree>{}) };

Tree rightmost(Tree root) {
	if (root.getChildren().empty()) {
		return root;
	}
	else {
		return rightmost(root.getChildren().back());
	}
}