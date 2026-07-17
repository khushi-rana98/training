#include <iostream>
#include <vector>
#include <queue>
#include <stack>
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
// count nodes of tree
int count(Node* root){
    if(!root) return 0;
    return 1+count(root->left)+count(root->right);
}
// height: no of edges
int height(Node* root) {
        // code here
        if(!root) return -1;
     return 1+max(height(root->left),height(root->right));   
    }
     int sumBT(Node* root) {
        if(!root) return 0;
        return root->data+sumBT(root->left)+sumBT(root->right);
    }
    // maximum nodes in the binary tree
    int countLeaves(Node* root){
        if(!root) return 0;
        if(!root->left && !root->right) return 1;
        return countLeaves(root->left)+countLeaves(root->right);
    }
    // zigzag traversal--
     vector<int> zigZagTraversal(Node* root) {
       if(!root) return {};
       vector<int>ans;
       queue<Node*>q;
       q.push(root);
       bool lefttoright=true;
       while(!q.empty()){
           int n=q.size();
           vector<int>level(n);
           int index=0;
           for(int i=0;i<n;i++){
               Node* temp=q.front();
               q.pop();
               if(lefttoright){
                   index=i;
               }
               else
               index=n-1-i; 
               level[index]=temp->data;
               if(temp->left) q.push(temp->left);
               if(temp->right) q.push(temp->right);
               
           }
           lefttoright=!lefttoright;
           for(int x: level)
          ans.push_back(x);
       }
       return ans;
    }
    // reversal level order traversal-- usiing stack and queue. queue to traverse level wise
    // and to get the data in reverse . there comes the stack
     vector<int> reverseLevelOrder(Node *root) {
       if(!root) return {};
       queue<Node*>q;
       stack<Node*>st;
       vector<int>ans;
       q.push(root);
       while(!q.empty()){
           Node* temp=q.front();
           q.pop();
           st.push(temp);
           if(temp->right) q.push(temp->right);
           if(temp->left) q.push(temp->left);
       }
       while(!st.empty()){
           Node* temp=st.top();
           st.pop();
           ans.push_back(temp->data);
       }
       return ans;
    }


// boundary traveral of binary tree
    bool isLeaf(Node* root){  // check if its leaf node
      return (root && !root->left && !root->right);
  }
  
//left boundary --maintaining the ans vector for left boundary--if left node exist updating it by it only else shift to right if it exists
    void leftBoundary(Node* root, vector<int>&ans){
     Node* curr=root->left;
     while(curr){
         if(!isLeaf(curr))
         ans.push_back(curr->data);
         if(curr->left) curr=curr->left;
         else
         curr=curr->right;
     }
    }
    // leaf nodes-- root exists but not its left and right child nodes--"AND"
    void leafNodes(Node* root, vector<int>&ans){
        if(!root) return;
        if(root && !root->left && !root->right) 
        ans.push_back(root->data);
        leafNodes(root->left,ans);
        leafNodes(root->right,ans);
    }
  
//   right boundary--> keep track of right boundary nodes in temp vector. if right child node exist updation goes wd it else shift left
    void rightBoundary(Node*root, vector<int>&ans){
        Node* curr=root->right;
        vector<int>temp;
        while(curr){
            if(!isLeaf(curr))
            temp.push_back(curr->data);
            if(curr->right)
            curr=curr->right;
            else
            curr=curr->left;
            
        }
        for(int i=temp.size()-1;i>=0;i--){
            ans.push_back(temp[i]);
        }
        
    }
    vector<int> boundaryTraversal(Node *root) {
       if(!root) return {};
       vector<int>ans;
       if(!isLeaf(root)) 
       ans.push_back(root->data);
       leftBoundary(root,ans); //left boundary
       leafNodes(root,ans); //leaf nodes
       rightBoundary(root,ans); //right boundary
       return ans;
    }
    // sum of left nodes
    int sumLeftNodes(Node* root){
        if(!root) return 0;
        int sum=0;
        if(root->left && !root->left->left && !root->left->right) return root->left->data;
        return sum+sumLeftNodes(root->left)+sumLeftNodes(root->right);
    }
    // left view of binary treee--
     vector<int> leftView(Node *root) {
       if(!root) return {};
       queue<Node*>q;
       q.push(root);
       vector<int>ans;
       while(!q.empty()){
           int size=q.size();
           for(int i=1;i<=size;i++){
               Node* temp=q.front(); q.pop();
               if(i==1)
               ans.push_back(temp->data);
               if(temp->left) q.push(temp->left);
               if(temp->right) q.push(temp->right);
           }
       }
       return ans;
    }
}; 