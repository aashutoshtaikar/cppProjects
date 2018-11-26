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

	int getNum() {
		return number;
	}

};

