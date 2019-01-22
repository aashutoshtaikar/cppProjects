//source : https://www.cprogramming.com/tutorial/lesson18.html
#pragma once

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
    // node *bad_searchSegFault(int key);
    node* search(int key);
    void destroy_tree();

    private:
    void destroy_tree(node *leaf);
    void insert(int key,node *leaf);
    // node* bad_searchSegFault(int key, node *leaf);
    node* search(int key,node *leaf);
    node *root;
};






