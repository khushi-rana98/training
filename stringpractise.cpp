#include <iostream>
#include <vector>

using namespace std;
bool isSubsequence(string s, string t){
    int s1=0;
    int t1=0;
    while(s1<s.size() && t1<t.size()){
        if(s[s1]==t[t1]){
            s1++;
            t1++;
        }
        else
        t1++;
    }
    if(s1==s.size()) return true;
    return false;

}
// class Solution {
//   public:
//     string firstRepChar(string s) {
//         vector<bool>seen(256,false);
//         // string ans="";
//         for(char c:s){
//             if(seen[c]){
//                 // ans+=c;
//                 return {c};
//             }
//             seen[c]=true;
//         }
//         return "-1";
//     }
// };
string first(string s){
    vector<bool>seen(256,false);
    for(char c:s){
        if(seen[c]){ //already seen: encountering for the 2nd time
            return {c};
        }
        seen[c]=true;
    }
    return "-1";
}
int main(){
    // valid angram
    //valid palindrom I
    // valid palindrome ii
    // is subsequnce
    // string s;
    // getline(cin,s);
    // string t;
    // getline(cin,t);
    // isSubsequence(s,t);

    // question 2: first repeated character hvin g2nd occeurence at lowest 
    // index
    string x;
    cout<<"Enter the string: ";
    getline(cin,x);
    string ans=first(x);
    cout<<"the repeated character hving its second occurence at lowest index is: "<<ans;
    return 0;
}