#include <iostream>
#include <string>
using namespace std;
void swap(char &a, char &b){
    char temp=a;
    a=b;
    b=temp;
}
string reverseString(string &s){
    int start=0;
    int end=s.length()-1;
    while(start<=end){
        swap(s[start],s[end]);
        start++;
         end--;
    }
    return s;
}
int main(){
    // string s;
    // cout<<"Enter a string: ";
    // getline(cin,s);
    // string str1="hey";
    // string str2="Hey";
    // if(str1==str2) cout<<"same";
    // else
    //  cout<<"not same";
     
    // question 1: 
    string x="khushi Rana";
    string res=reverseString(x);
    cout<<"The reversed string is: "<<res;

   
}