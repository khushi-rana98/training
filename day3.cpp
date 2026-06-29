#include <iostream>
#include <climits>
using namespace std;
int maxSubarray(int a[], int n){
    int c_sum=0;
    int max_sum=INT_MIN;
    for(int i=0;i<n;i++){
        c_sum+=a[i];
        max_sum=max(c_sum,max_sum);
        if(c_sum<0) c_sum=0;
    }
return max_sum;
}
int main(){
    int n;
    cin>>n;
    int *a=new int[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int x=maxSubarray(a,n);
    cout<<"The max Sum is: "<<x;
    return 0;
}