#include <iostream>
using namespace std;
// binary search tree-> left child is smaller than root and right child is greater than root
    // BST is a binary tree with the properies:
    // in case a tree has inorder as sorted arrya then its a BST
    //
class Node{
public:
Node* left;
Node* right;
int data;
Node(int val){
    left=NULL;
    right=NULL;
    data=val;
}
};
class BinarySearchTree{
// leetcode 700
 Node* searchBST(Node* root, int val) {
        if(!root) return NULL;
        if(root->data==val) return root;
        if(root->data>val) 
        return searchBST(root->left,val);
        if(root->data<val) 
        return searchBST(root->right,val);
        return root;
    }
};
