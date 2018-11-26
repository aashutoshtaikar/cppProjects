#pragma once
//source : https://www.cprogramming.com/tutorial/lesson18.html
#include<iostream>
using namespace std;

struct node{
    int key_value;
    node *left;
    node *right;
};

class BTree{
    public:
    BTree();
    ~BTree();

    void insert(int key);
    node *search(int key);
    void destroy_tree();

    private:
    void destroy_tree(node *leaf);
    void insert(int key,node *leaf);
    node *search(int key, node *leaf);

    node *root;
};

//constructor
BTree::BTree(){
    root=NULL;
}

//destructor
BTree::~BTree(){
    destroy_tree();
}

void BTree::destroy_tree(){
    destroy_tree(root);
}

void BTree::destroy_tree(node *leaf){
    //destroy
}

void BTree::insert(int key,node *leaf){
    //
}

node* BTree::search(int key, node *leaf){
    //
}





