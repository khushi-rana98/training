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
class LinkedList{
    public:
    Node* head;
    LinkedList(){
        head=NULL;
    }
    // reverse Linked list:
   Node* reverseList(Node* curr){
        Node* prev=NULL;
        while(curr){
            Node* fut=curr->next; 
            curr->next=prev;
            prev=curr;
            curr=fut;
        }
        return prev;
    }
    // reverse linked list using recursion:
    Node* reverseList(Node* curr, Node*prev){
        if(!curr) return prev;
        Node* fut=curr->next;
        curr->next=prev;
        return reverseList(fut,curr);
    }
    void reverseRecursion(Node* head){
        if(!head) return;
        Node* prev=nullptr;
        head=reverseList(head,prev);
    }
    //    Partition List
// Odd Even Linked List
// Sort List
// Reverse Linked List
// Find Middle Node
// Detect Loop/Cycle
// Remove Nth Node from End
// Merge Two Sorted Lists
// Palindrome Linked List
// Intersection of Two Lists
// insert at 
// odd even in linked list
// reverse linked list in k groups
// Reverse in K Groups (for stronger companies)
// Sort Linked List
// Delete Node / Insert Node
};
