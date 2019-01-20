#include<iostream>
#include"Tree.h"
#include<string>

using namespace std;


int count(Tree n);
int sumNum(Tree t); 
Tree last(Tree root);
int countTreeAtLevel(Tree n, int level);

int main(){

	list<Tree> t1 = list<Tree>{ Tree(2,list<Tree>{Tree(6,list<Tree>{})}), Tree(1,list<Tree>{}) };
	list<Tree> t2 = list<Tree>{ Tree(0,list<Tree>{}),Tree(1,list<Tree>{Tree(2,list<Tree>{}),Tree(3,list<Tree>{})}), Tree(4,list<Tree>{}) };
	Tree x = Tree(5, t2);
	cout<<"countTree: "<< count(x)<<endl;
	cout << "countTreeAtLevel 1 is" << countTreeAtLevel(x, 1)<<endl;

	if (sumNum(x) == 6) {
		printf("Success");
	}
	return 0;
}

int count(Tree t) {
	int cnt = 1;
	for (Tree c : t.getChildren()) {
		cnt = cnt + count(c);
	}
	return cnt;
}

int sumNum(Tree t) {
	int sum = 0;
	sum = sum + t.getNum();
	for (Tree c : t.getChildren()) {
		sum = sum + sumNum(c);
	}
	return sum;
}

//Q. Calculate the number of element for each level in Tree
int countTreeAtLevel(Tree n, int level) {
	int cnt = 0;
	for (Tree c: n.getChildren()) {
		if (c.getNum() == level) {
			for(Tree c: c.getChildren()){
				cnt++;
			}	
		}
	}
	return cnt;
}

//Calculate the number of element for each level in Tree by recursion
int countTreeAt(Tree t, int num) {
	int count;
	count++;
	for (Tree c:t.getChildren()) {
		if (num == t.getNum()) {
			//incomplete
		}	
	}
}

//Q.Get the last Tree node from given Tree root node
Tree last(Tree root) {
	if (root.getChildren().empty()) {
		return root;
	}
	else{
		//list<Tree>::iterator it = prev(root.getChildren.end());
		return last(root.getChildren().back());
	}
}

//Search for num in the given Tree
bool searchTree(Tree t, int num) {
	if (num == t.getNum()) return true;
	bool contains = false;
	for (Tree c : t.getChildren()) {
		contains = contains || searchTree(c, num);
	}
}
