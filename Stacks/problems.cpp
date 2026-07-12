#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void reverse(vector<int>&a){
    stack<int> s;
    int n=a.size();
    for(int i=0;i<n;i++){
        s.push(a[i]);
    }
    int i=0;
    while(!s.empty()){
       a[i++]=s.top();
        s.pop();
    }
    
}
void insertAtBottom(stack<int>&st){
    int toinsert=3;
    stack<int>temp;
    while(!st.empty()){
        temp.push(st.top());
        st.pop();
    }
    temp.push(toinsert);
    while(!temp.empty()){
        st.push(temp.top());
        temp.pop();
    }
}
int main(){
    // reverse array
    int n;
    cout<<"Enter the size of array: ";
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    reverse(a);
    cout<<"reversed array: ";
    for(int i=0;i<a.size();i++){
        cout<<a[i]<<" ";
    }
    return 0;
}
