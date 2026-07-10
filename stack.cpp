#include <iostream>
#include <stack>
using namespace std;
int main(){
    stack<int>s;
    s.push(2);
    s.push(3);
    s.push(21);
    cout<<"Top elmnt in the stack: "<<s.top();
    return 0;
}