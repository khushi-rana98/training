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
    Node* reverseRecursion(Node* curr, Node* prev){
        if(!curr){
            return prev;
        }
        Node* fut=curr->next;
        curr->next=prev;
        return reverseRecursion(fut,curr);
    }
};