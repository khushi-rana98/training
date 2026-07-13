#include <iostream>
#include <vector>
#include <stack>
#include <queue>
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
  stack<int>delete_1(stack<int>st, int size, int count){
        if(count==size/2){
            st.pop();
            return st;
        }
        int top=st.top();
        st.pop();
        st=delete_1(st,size,count+1);
        st.push(top);
        return st;
    }
    void deleteMid(stack<int>& s) {
        int size=s.size();
        int count=0;
        s=delete_1(s,size,count);
        while(!s.empty()){
            cout<<s.top()<<" ";
            s.pop();
        }
    }

    class MinStack {
    stack<int>st;
    stack<int>minst;
public:
    MinStack() {
       
    }
    
    void push(int value) {
        st.push(value);
        if(minst.empty())
        minst.push(value);
        else
        minst.push(min(value, minst.top()));
    }
    
    void pop() {
        st.pop();
        minst.pop();
    }
    
    int top() {
        return st.top();
        
    }
    
    int getMin() {
        return minst.top();
    }
};
stack<int> insertAtBottom(stack<int> st, int x) {
      if(st.empty()){st.push(x);
          return st;
      }
      int top=st.top();
      st.pop();
      st=insertAtBottom(st,x);
      st.push(top);
    return st;
}
int minAddToMakeValid(string s) {
       stack<int>st;
       for(char c:s){
        if(c=='(') st.push(c);
        else{
            if(!st.empty() && st.top()=='(')
            st.pop();
            else
            st.push(')');
        }
       }
       return st.size();
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
vector<int>makeArrayBeautiful(vector<int>&arr){
    stack<int>s;
    for(int i=0;i<arr.size();i++){
        if(!s.empty() && ((arr[i]>=0 && s.top()<0)||(arr[i]<0 && s.top()>=0)))
        s.pop();
        else
        s.push(arr[i]);
    }
    vector<int>ans(s.size());
    for(int i=s.size()-1;i>=0;i--){
        arr[i]=s.top();
        s.pop();
    }
    return arr;
}

vector<string> stringManipulation(vector<string>a){
    int n=a.size();
    stack<string>st;
    for(int i=0;i<n;i++){
        if(!st.empty() && st.top()==a[i])
        st.pop();
        else
        st.push(a[i]);
    }
    vector<string>ans(st.size());
    int index=st.size()-1;
    for(int i=index;i>=0;i--){
        ans[i]=st.top();
        st.pop();
    }
    return ans;
}
// reverese a queue 
void reverese(queue<int>&q){
    stack<int> st;
    while(!q.empty()){
        st.push(q.front());
        q.pop();
    }
    while(!st.empty()){
        q.push(st.top());
        st.pop();
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
    // reverese queue using stack and recursion
    // implmnt stack using queue and queues
    // min stack
    // reverese stack using recursion
    // mid value of stack 
    return 0;
}
