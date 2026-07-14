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
class Solution{
public:
    // 1.reverse linked list
    Node* reverseRecursion(Node* curr, Node* prev){
        if(!curr){
            return prev;
        }
        Node* fut=curr->next;
        curr->next=prev;
        return reverseRecursion(fut,curr);
    }
    // 2.find mid of linked list
    Node* middleNode(Node* head) {
    Node* slow=head;
    Node* fast=head;
    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
    }
};