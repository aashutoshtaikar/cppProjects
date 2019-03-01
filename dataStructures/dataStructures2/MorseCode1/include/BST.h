#pragma once
#include <string>
#define COUNT 10 

struct Node
{
    std::string letter;
    std::string code;
    Node *left;
    Node *right;
};

class BSTree{  
  
  public:
    BSTree();
    ~BSTree();

    void destroy_tree(Node *leaf);
    void insert(std::string letter, std::string code);
    void insert(std::string letter, std::string code, Node *&leaf);
    Node *search(int key, Node *leaf);
    void print2DUtil(Node *root, int space);

    Node *root;

};

//public

BSTree::BSTree()
{
    root = NULL;
}

BSTree::~BSTree()
{
    destroy_tree(root);
}

void BSTree::destroy_tree(Node *leaf){
    if(leaf!=NULL){
        destroy_tree(leaf->left);
        destroy_tree(leaf->right);
        delete leaf;
    }
}

void BSTree::insert(std::string letter, std::string code, Node *&leaf)
{
    if (leaf == NULL)
    {
        leaf = new Node;
        leaf->letter = letter;
        leaf->code = code;
        leaf->left = NULL;
        leaf->right = NULL;
    }
}

//private

void BSTree::insert(std::string letter, std::string code)
{
    Node **leaf = &root;
    if (*leaf != NULL)
    {
        for (std::string::size_type i = 0; i < code.length(); i++){
            if (code[i] == '.') leaf = &((*leaf)->left);
            else if (code[i] == '-') leaf = &((*leaf)->right);
            else break;
        }
        insert(letter,code,*leaf);
    }
    else{
        insert(letter,code,root);
    }
}

void BSTree::print2DUtil(Node *root, int space) 
{ 
    // Base case 
    if (root == NULL) 
        return; 
  
    // Increase distance between levels 
    space += COUNT; 
  
    // Process right child first 
    print2DUtil(root->right, space); 
  
    // Print current node after space 
    // count 
    printf("\n"); 
    for (int i = COUNT; i < space; i++) 
        printf(" "); 
    std::cout << root->letter; 
  
    // Process left child 
    print2DUtil(root->left, space); 
} 
