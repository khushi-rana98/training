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
int main(){
    // slow and fast method: find mid
}