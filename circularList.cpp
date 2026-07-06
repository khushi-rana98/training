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
// insert at begin
void insertAtEnd(Node *start, int data){
    Node *n=new Node(data);
    Node*temp=start;
    while(temp->next!=start){
        temp=temp->next;
    }
    n->next=start;
    temp->next=n;
}
// insertion at end
void insertAtEnd(Node *start, int data){
    Node*n=new Node(data);
    Node*temp=start;
    // if list is empty
    if(!start){
        start=n;
        n->next=start;
    }
    while(temp->next!=start){
        temp=temp->next;
    }
    
    n->next=start;
    temp->next=n;
    start=n;
}
int main(){

}