#include<iostream>
#include "BTree.h"
using namespace std;

int main(){
    BTree myTree;
    myTree.insert(1);
    myTree.insert(2);
    myTree.insert(3);

    node* temp = nullptr;
    temp = myTree.search(1);
    cout << temp->key_value;
    delete temp;

    return 0;
}

