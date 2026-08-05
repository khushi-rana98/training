#include <iostream>
#include <stack>
using namespace std;

bool isValidParenthesis(string s) {
        stack<char>st;
        for(char c:s){
            if(c=='(' || c=='[' || c=='{') // when we get open brackets. push them into stack
            st.push(c);
            else{
                if(st.empty()) return false; // case: }]]] handling this 
                    char top=st.top();
                    st.pop();
                    if(c==')' && top!='(') 
                    return false;
                    if(c==']' && top!='[')
                    return false;
                    if(c=='}' && top!='{')
                    return false;
                
            }

        }
        return st.empty(); // handling this [( case: if stack is not empty then return false
    }
    // simplify path--string and stack problem
    class Solution {
public:
    string simplifyPath(string path) {
        stack<string>st;
        string curr="";
        for(int i=0;i<=path.size();i++){
            if(i==path.size() || path[i]=='/'){
                if(curr=="" || curr=="."){}
                else if(curr==".."){
                    if(!st.empty())
                    st.pop();
                    }
                else
                st.push(curr);
                curr="";
            }
            else
            curr+=path[i];
        }
        vector<string>dirs;
        while(!st.empty()){
            dirs.push_back(st.top());
            st.pop();
        }
        reverse(dirs.begin(),dirs.end()); //reversed the directories
        string ans="";
        for(string s:dirs){
            ans+="/"+s;
        }
        return ans.empty()?"/":ans;
    }
};
int main(){
    stack<int>s;
    s.push(2);
    s.push(3);
    s.push(21);
    cout<<"Top elmnt in the stack: "<<s.top();

    // queue: printer.
    // multiple messages 
    
    return 0;
}