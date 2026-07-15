#include <iostream>
using namespace std;
// Trees-->binary Tree-- atmost 2 nodes-->0,1,2
class Node{
public:
int data;
Node* left;
Node* right;
Node(int val){
    left=right=nullptr;
    data=val;
}
};
class Trees{
public:
void inorder(Node *root){
    if(!root) return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
};