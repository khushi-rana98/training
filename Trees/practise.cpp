#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <map>
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
     vector<int> reverseLevelOrder(Node *root) 
     {
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
     bool isLeaf(Node* root){
      if(!root) return false;
      return (root && !root->left && !root->right);
  }
    void leftTraversal(Node* root,  vector<int>&ans){
        if(!root) return;
        if(!isLeaf(root))
        ans.push_back(root->data);
        if(root->left) leftTraversal(root->left,ans);
        else
        leftTraversal(root->right,ans);
    }
    void leafTraversal(Node* root, vector<int>&ans){
        if(!root) return;
        if(root && !root->left && !root->right)
        ans.push_back(root->data);
        leafTraversal(root->left,ans);
        leafTraversal(root->right,ans);
    }
    void rightTraversal(Node* root, vector<int>&ans){
        if(!root || (root && !root->left && !root->right)){
            return;
        }
        if(root->right) rightTraversal(root->right,ans);
        else 
        rightTraversal(root->left,ans);
        ans.push_back(root->data);
    }
    vector<int> boundaryTraversal(Node *root) {
        if(!root) return {};
        
        vector<int>ans;
        if(!isLeaf(root))
        ans.push_back(root->data);
        leftTraversal(root->left,ans);
        leafTraversal(root,ans);
        rightTraversal(root->right,ans);
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
    // top view of binary tree00
     vector<int> topView(Node *root) {
        // code here
        if(!root) return {};
        vector<int>ans;
        map<int, int>mp;
        queue<pair<Node*,int>>q;
        
        q.push(make_pair(root,0));
        while(!q.empty()){
            pair <Node*, int>frontNode=q.front();
            q.pop();
            Node* node=frontNode.first;
            int dist=frontNode.second;
            if(mp.find(dist)==mp.end()){
               mp[dist]=node->data;
            }
            if(node->left)
            q.push(make_pair(node->left,dist-1));
            if(node->right)
            q.push(make_pair(node->right,dist+1));
        }
        for(auto it:mp){
            ans.push_back(it.second);
        }
        return ans;
    }
    // k distance from root node--
    vector<int> kdistance(int k, Node *root) {
        if(!root) return {};
        vector<int>ans;
        queue<Node*>q;
        int level=0;
        q.push(root);
        while(!q.empty()){
            int size=q.size();

            if(level==k){
                while(!q.empty()){
                    ans.push_back(q.front()->data);
                    q.pop();
                }
                return ans;
            }
            else{
                for(int i=1;i<=size;i++){
                    Node* temp=q.front();
                    q.pop();
                    if(temp->left) q.push(temp->left);
                    if(temp->right)q.push(temp->right);
                    
                }
                level++;
            }
        }
       return {};
        
    }
    // lowest common ancestor of binary tree--
    Node* lowestCommonAncestor(Node* root, Node* p, Node* q) {
        if(!root) return NULL;
        // any one of p or q is root its the descendatnt
        if(root==p || root==q) return root;
       Node* left_ans=lowestCommonAncestor(root->left,p,q);
       Node* right_ans=lowestCommonAncestor(root->right,p,q);
       if(left_ans && right_ans) return root;
       else if(left_ans && !right_ans) return left_ans;
       else if(!left_ans && right_ans) return right_ans;
       else return NULL;
    } 
    // insert a node in BST--
    Node* insertIntoBST(Node* root, int val) {
        if(!root){
            Node* n=new Node(val);
            return n;
        }
        if(root->data > val)
         root->left=insertIntoBST(root->left,val);
        else
        root->right=insertIntoBST(root->right,val);
        return root;
    }

    // two sum in BST--leetcode 653
void inorder(Node* root,vector<int>&ans){
    if(!root) return;
    inorder(root->left,ans);
    ans.push_back(root->data);
    inorder(root->right,ans);

}
    bool findTarget(Node* root, int k) {
        vector<int>ans;
        inorder(root,ans);
        int st=0;
        int e=ans.size()-1;
        while(st<e){
            if(ans[st]+ans[e]==k) return true;
            else if(ans[st]+ans[e]>k)
            e--;
            else
            st++;
        }
        return false;
    }
    
void inorder(vector<int>&ans, Node* root){
        if(!root) return;
        inorder(ans,root->left);
        ans.push_back(root->data);
        inorder(ans,root->right);
    }
    int kthSmallest(Node* root, int k) {
        vector<int>ans;
        inorder(ans,root);
        if(k<=ans.size())
        return ans[k-1];
        return -1;
    }
    // build a balancd BST from sorted array--Leetcode 108
     Node* build( vector<int>&nums, int st, int e){
        if(st>e) return NULL;
        int mid=st+(e-st)/2;
        Node* root=new Node(nums[mid]);
        root->left=build(nums,st,mid-1);
        root->right=build(nums,mid+1,e);
        return root;
    }
    Node* sortedArrayToBST(vector<int>& nums) {
        int st=0;
        int end=nums.size()-1;
        Node* root=build(nums,st,end);
        return root;

    }
    // validate BST--Leetcode 98
    #include <climits>
    bool validate(Node* node, long long min,long long max){
        if(node==NULL) return true;
        if(node->data<=min || node->data >=max) return false;
        return validate(node->left,min,node->data) && validate(node->right,node->data,max);
    }
    bool isValidBST(Node* root) {
        return validate(root,INT_MIN, INT_MAX);
    }
    // deletion in BST--
     Node* pred(Node* root) {
        while (root->right) {
            root = root->right;
        }
        return root;
    }

    Node* deleteNode(Node* root, int key) {
        if (!root) return nullptr;

        if (key < root->data) {
            root->left = deleteNode(root->left, key);
        }
        else if (key > root->data) {
            root->right = deleteNode(root->right, key);
        }
        else { // node found

            // Case 1: Leaf node
            if (!root->left && !root->right) {
                delete root;
                return nullptr;
            }

            // Case 2: One child
            if (!root->left) {
                Node* temp = root->right;
                delete root;
                return temp;
            }

            if (!root->right) {
                Node* temp = root->left;
                delete root;
                return temp;
            }

            // Case 3: Two children
            Node* temp = pred(root->left);
            root->data = temp->data;
            root->left = deleteNode(root->left, temp->data);
        }

        return root;
    }
}; 