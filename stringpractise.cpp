#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <stack>
using namespace std;

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
// smart method:
string binaryoperations2(string s1,string s2, string op){
    string ans="";
    int i=s1.size()-1;
    int j=s2.size()-1;
    while(i>=0 || j>=0){
        int a=0,b=0;
        if(i>=0) a=s1[i]-'0';
        if(j>=0) b=s2[j]-'0';
        if(op=="AND")
        ans+=(a&b)+'0';
        else if(op=="OR")
        ans+=(a|b)+'0';
        else if(op=="XOR")
        ans+=(a^b)+'0';
        i--;
        j--;
    }
    reverse(ans.begin(),ans.end());
    return ans;
}
// check if two strings are anagram:
//anagram: frequency of each character in both strings should be same
// sort both strings and compare them --it takes O(nlogn) time
// smart way: count frequncy of each character in first array
// decrease frequncy of each character in second array
// if frequcy of eachcharacter turns 0. then its anagram
bool isAnagram(string s, string t){
    if(s.size()!=t.size()) return false;
    vector<int> freq(26,0);
    for(char c:s){ //increasinf the frequncy count for string1
        freq[c-'a']++;
    }
    for(char c:t){
        freq[c-'a']--; //decreasing the frequncy count for string2
    }
    for(int i=0;i<26;i++){
        if(freq[i]!=0) return false;
    }
    return true;
}
// reverse words ina string: "the sky is blue"-->"blue is sky the"
 string reverseWords(string s) {
     int i=s.size()-1;
     vector<string>ans;
     string result="";
     while(i>=0){
        while(i>=0 && s[i]==' ')
        i--;
        if(i<0) break;
        int j=i;
        while(i>=0 && s[i]!=' ')
        i--;
        string word=s.substr(i+1, j-i);
        ans.push_back(word);
    }
    for(string s2: ans){
        if(result.empty()) result+=s2;
        else 
        result+=" "+s2;
    }
    return result;
    }
    // frequency sort--
     string frequencySort(string s) {
        unordered_map<char,int>mp;
        //storing the frequency of characters in map 
        for(char c:s)
        mp[c]++;

        // step 2: store pairs
        vector<pair<char,int>>arr;

        for(auto it:mp){
            arr.push_back(make_pair(it.first,it.second));
        }
        // step 3: sort the pairs based on frequncy
        sort(arr.begin(),arr.end(),
        [](pair<char,int>&a, pair<char,int>&b){
            return a.second>b.second;
        });
        string ans="";
        for(auto it:arr){
            char ch=it.first;
            int count=it.second;
            while(count--){
                ans+=ch;
            }
        }
        return ans;

    }
    // frequncy sort-- 
    // remember , numbers are sorted based on num if their frequencies are same..--leetcode 1636
     vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int,int>mp;
        // store the frequency of all numbers
        for(int n:nums)
        mp[n]++;
        // sort them into an array so i can sort it later
        vector<pair<int,int>>ans;
        for(auto it: mp){
            ans.push_back(make_pair(it.first,it.second));
        }
        // sort them based on frequncy
        sort(ans.begin(),ans.end(),[](auto&a, auto &b){
            if(a.second==b.second)
            return a.first>b.first;
            return a.second<b.second;
        });
        // store the ans in rsultant vector
        vector<int>result;
        for(auto it:ans){
            int num=it.first;
            int count=it.second;
            while(count--)
            result.push_back(num);
        }
        return result;
    }

// remove duplicates from string: min laxicographical order
// remember: if we just need to remove duolicates. we could hv used the unordered_set, unordered_map or freq array
// to keep check if this character has been seen or not.but here we need to remove duplicates and also return the 
// string in min lexicographical order
string removeDuplicateLetters(string s) {
       vector<int>freq(26,0);
    //    store the freq of each character of string
       for(char c:s){
        freq[c-'a']++;
       }
       vector<bool>visited(26,0);
       stack<char>st;
       for(char c:s){
        freq[c-'a']--; //decrease the freq
        if(visited[c-'a']) continue; //already present in the answer
        while(!st.empty() && freq[st.top()-'a']!=0 &&
        st.top()>c){
            visited[st.top()-'a']=0;
            st.pop();
        }
        st.push(c);
        visited[c-'a']=1;
       }
       string ans="";
       while(!st.empty()){
        ans+=st.top();
        st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
    // detect capitals--leetcode 520
     bool detectCapitalUse(string word) {
        int len=0;
        // counting the length of string
        for(char c:word){
            len++;
        }
        // count of upperCases
        int uCount=0;
        for(char c:word){
            if(c>='A' && c<='Z')
                uCount++;
        }
        // case 1: no uppercase letter or 
        // case 2: all uppercase letters
        if(uCount==0 || uCount==len ) return true;
        
        if(uCount==1 && word[0]>='A' && word[0]<='Z') return true;
        return false;
    }
// permute palindrome: we dont need to find all permutations of string. instead remember: a palindome has:
// either even count of each character OR even count and exctly one odd count
// for this problem : we count frequency of each character-->
// count how many characters hv oddCount
//  if oddCount>1 palindrome not posible for the string
// if oddCOunt<=1 palindrome possible
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