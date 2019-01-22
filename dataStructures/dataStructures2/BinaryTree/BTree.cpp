#include "BTree.h"
//constructor
BTree::BTree(){
    root=nullptr;
}

//destructor
BTree::~BTree(){
    destroy_tree();
}

//public:
void BTree::destroy_tree(){
    destroy_tree(root);
}

void BTree::insert(int key){
    if(root!=nullptr){            //if root is present
        insert(key,root);
    }
    else{                    //create root
        root = new node;
        root->key_value=key;
        root->left = nullptr;
        root->right=nullptr;
    }
}

// node* BTree::bad_searchSegFault(int key){
//     return bad_searchSegFault(key,root);
// }

node* BTree::search(int key){
    return search(key,root);
}


//private:
void BTree::destroy_tree(node *leaf){
    if(leaf!=nullptr){
        destroy_tree(leaf->left);
        destroy_tree(leaf->right);
        delete leaf;
    }
}

void BTree::insert(int key,node *leaf){
    if(key < leaf->key_value){
        if(leaf->left!=nullptr){
            insert(key,leaf->left);
        }
        else{
            leaf->left=new node;
            leaf->left->key_value = key;
            leaf->left->left = nullptr;
            leaf->left->right = nullptr;
        }
    }
    else if(key > leaf->key_value){
        if(leaf->right!=nullptr){
            insert(key,leaf->right);
        }
        else{
            leaf->right = new node;
            leaf->right->key_value = key;
            leaf->right->left = nullptr;
            leaf->right->right = nullptr;
        }
    }
}

// node* BTree::bad_searchSegFault(int key, node *leaf){
//     if(key<leaf->key_value){
//         if(leaf->left!=nullptr){
//             bad_searchSegFault(key,leaf->left);
//         }
//         else{
//             return leaf;
//         }
//     }
//     else if(key>leaf->key_value){
//         if(leaf->right!=nullptr){
//             bad_searchSegFault(key,leaf->right);
//         }
//         else{
//             return leaf;
//         }
//     }
// }



node* BTree::search(int key,node *leaf){
    if(leaf!=nullptr){
        if(key==leaf->key_value){
            return leaf;
        }
        if(key<leaf->key_value){
            search(key,leaf->left);
        }
        else{
            search(key,leaf->right);
        }
    }
}