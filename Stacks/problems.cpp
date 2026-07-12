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
