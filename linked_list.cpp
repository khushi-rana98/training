#include <iostream>
using namespace std;
class Node{
    int data;
    Node *next;
    Node(int val){
        data=val;
        next=NULL;
    }
};
void deleteAtEnd(Node* &start){
    Node*temp=start;
    if(start==NULL) return;
    if(start->next==NULL){
        delete start;
        start=NULL;
        return;
    }
    while(temp->next->next!=NULL){
        temp=temp->next;
    }
    delete temp->next;
    temp->next=NULL;
}
void deleteAtBegin(Node *&start){
    if(start==NULL) return; //if linked list is empty
    Node *temp=start;
    start=temp->next; //either its null or linked list
    delete temp;

}
int main(){
// 4 patterns:
// fast and slow
// reversal
// gap
// dummy node
}