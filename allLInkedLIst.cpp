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
    // remember the intuition: slow pointer moves 1 step and fast pointer moves 2 steps at a time. if there is a loop in linked list
    // when both pointers enter loop. notice: fast pointer gain one node over slow pointer in each iteration. means, increases the gap by 1 
    // over every iteration. since, the length of loop is finite. there is a time, when relative distance between both pointers 
    // starts like 1-> 2 ->3 -> 4->5 the gap btween both pointers. lets say the cycle length is 5. the relative distance
    // betweenboth pointers is 0 when the gap is 5. so the fast pointer will meet the slow pointer at some point in the
    // loop. so , we can say tht there is a loop in linked list.
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

    // merge two sorted linked list: using dummy node-- we can do this wdout extra node also. then we hv to deal wd
    // first node of both linked list to avoid dummy node.
    Node* mergeTwoLists(Node* list1, Node* list2) {
    Node* dummy = new Node(-1);
    Node* temp = dummy;

    while(list1 && list2) {
        if(list1->data <= list2->data) {
            temp->next = list1;
            list1 = list1->next;
        }
        else {
            temp->next = list2;
            list2 = list2->next;
        }

        temp = temp->next;
    }

    temp->next = (list1) ? list1 : list2;

    return dummy->next;
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


// Detect Loop/Cycle ---
// Remove Nth Node from End 
// Merge Two Sorted Lists ---
// Palindrome Linked List
// Intersection of Two Lists
// insert at 
// odd even in linked list
// reverse linked list in k groups
// Reverse in K Groups (for stronger companies)
// Sort Linked List
// Delete Node / Insert Node
};
