#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
// permute palindrome: we dont need to find all permutations of string. instead remember: a palindome has:
// either even count of each character OR even count and exctly one odd count
// for this problem : we count frequency of each character-->
// count how many characters hv oddCount
//  if oddCount>1 palindrome not posible for the string
// if oddCOunt<=1 palindrome possible
// binary operations on strings
string binaryoperations(string s1, string s2, string op){
    string ans="";
    for(int i=0;i<max(s1.size(), s2.size());i++){
        if(op=="AND"){
           if(s1[i]=='1' && s2[i]=='1')
           ans+='1';
           else
              ans+='0';
        }
        else if(op=="OR"){
            if(s1[i]=='0' && s2[i]=='0')
            ans+='0';
            else
            ans+='1';
        }
        else if(op=="XOR"){
            if(s1[i]!=s2[i])
            ans+='1';
            else
            ans+='0';
        }
        // ans += (!(a^b)) + '0'; this is for X-nor means not xor
    }
    return ans;
}
bool canPermutePalindrome(string s){
    unordered_map<char,int>freq;
    for(char ch:s)
    freq[ch]++;

    int oddCount=0;
    for(auto it:freq){
        if(it.second%2!=0)
        oddCount++;
    }
    return oddCount<=1;

}
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