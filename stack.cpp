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