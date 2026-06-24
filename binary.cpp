#include <iostream>
using namespace std;
int sqrt(int num){
    int s=0;
    int e=num;
    int ans=0;
    while(s<=e){
        int mid=s+(e-s)/2;
        if(mid*mid==num) return mid;
        else if(mid*mid<num){
            ans =mid;
            s=mid+1;
        }
        else
        e=mid-1;
    }
    return ans;
}
int main(){
    int x;
    cin>>x;
    cout<<sqrt(x);
    return 0;
}