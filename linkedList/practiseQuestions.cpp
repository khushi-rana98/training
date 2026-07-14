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
// remove nth node from end of linked list
    Node* removeNthFromEnd(Node* head, int n) {
    int count = 0;
    Node* temp = head;

    while (temp) {
        count++;
        temp = temp->next;
    }

    count = count - n;

    Node* prev = NULL;
    Node* curr = head;

    while (count--) {
        prev = curr;
        curr = curr->next;
    }

    if (curr == head) {
        head = curr->next;
        delete curr;
    }
    else {
        prev->next = curr->next;
        delete curr;
    }

    return head;
}
// using gap method:making the gap first. when fast is null. we just get the slow at nod. hving gap of n nodes
Node* removeNthFromEnd(Node* head, int n) {
    Node* dummy = new Node(0);
    dummy->next = head;

    Node* slow = dummy;
    Node* fast = dummy;

    for(int i = 0; i <= n; i++) {
        fast = fast->next;
    }

    while(fast) {
        slow = slow->next;
        fast = fast->next;
    }

    Node* todel = slow->next;
    slow->next = todel->next;
    delete todel;

    head = dummy->next;
    delete dummy;

    return head;
}
// delete every kth node
   Node* deleteK(Node* head, int K) {
       Node* prev=NULL;
       Node* curr=head;
       int count=1;
       while(curr){
           if(count==K){
               prev->next=curr->next;
               delete curr;
               curr=prev->next;
               count=1;
           }
           else{
               prev=curr;
               curr=curr->next;
               count++;
           }
       }
        return head;
    }
};