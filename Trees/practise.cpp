#include <iostream>
#include <vector>
#include <queue>
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
void preorder(Node* root){
    if(!root) return;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
// postorder is used for bottom-up processing: deletion
// left->right->root

// level order traversal-->
vector<vector<int>> levelOrder(Node* root) {
    if (!root)
        return {};

    vector<vector<int>> ans;
    queue<Node*> q;

    q.push(root);

    while (!q.empty()) {

        int size = q.size();
        vector<int> res;

        for (int i = 0; i < size; i++) {

            Node* temp = q.front();
            q.pop();

            res.push_back(temp->data);

            if (temp->left)
                q.push(temp->left);

            if (temp->right)
                q.push(temp->right);
        }

        ans.push_back(res);
    }

    return ans;
}
int height(Node* root){
    if(!root) return 0;
 return 1+max(height(root->left),height(root->right));
}

}; 