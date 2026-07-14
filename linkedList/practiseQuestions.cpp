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
};