#pragma once

#include<list>
using namespace std;

class Tree {
	int number;
	list<Tree> children;
public:

	Tree(int n, list<Tree> ns) {
		number = n;
		children = ns;
	}

	list<Tree> getChildren()const{
		return children;
	}

	int getNum()const{
		return number;
	}

};

