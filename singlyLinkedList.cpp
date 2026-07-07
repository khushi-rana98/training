#include <iostream>
using namespace std;
class Node{
public:
int data;
Node* next;
Node(int val){
    data=val;
    next=NULL;
}
};
Node* findMid(Node* root){
    Node* slow=root;
    Node* fast=root;
    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
}
Node* reversal(Node *head){
    Node*curr=head;
    Node* prev=NULL;
    Node* fut=NULL;
    while(curr){
        fut=curr->next;
        curr->next=prev;
        
    }
}
int main(){
    // slow and fast method: find mid
    // reversal 
}