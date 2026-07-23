#include <iostream>
#include <unordered_map>
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

    // find middle node of linked list:
    // remember: if 2 person cover the same distance. one wd double of another. when the one wd double speed complete tht distance, 
    // another one reaches exct half of the distance.so, if we have 2 pointers, one moving at double spped of another,
    // when the faster one reaches the end of linked list, the slower one will b at middle of linked list.
    Node* middleNode(Node* head) {
    Node* slow=head;
    Node* fast=head;
    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
    }
    // detet loop in linked list:
    // method 1: using unordered_map means hashing or set to store the address of nodes. 
    // it take O(n) time to traverse the linked list n O(n) space to stire the addresses
     bool detectLoop(Node* head) {
      unordered_map<Node*,int>mp;
       while(head){
        if(mp[head]==1) return true;
        mp[head]=1;
        head=head->next;
       }
       return false;
    }
    // method 2: detect cycle in linked list: using slow and fast pointer
    bool detectLoop(Node* head){
        Node* slow=head;
        Node* fast=head;
        while(fast!=nullptr && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast) return true;
        }
        return false;
    }
    // length of loop in linked list:
     int lengthOfLoop(Node *head) {
      Node*slow=head;
      Node* fast=head;
      while(fast!=NULL && fast->next!=NULL){
          slow=slow->next;
          fast=fast->next->next;
          if(slow==fast) break;
      }
      if(!fast || !fast->next) return 0;
      int count=1;
      slow=fast->next;
      while(slow!=fast){
          count++;
          slow=slow->next;
          
      }
      return count;
    }
    //    Partition List
// Odd Even Linked List
// Sort List


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
