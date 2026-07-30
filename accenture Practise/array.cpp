#include <iostream>
using namespace std;
int superiorelmnt(int a[], int n){
    int count=1;
    int maxi=a[n-1];
    for(int i=n-2;i>=0;i--){
        if(a[i]>maxi){
            count++;
            maxi=a[i];
        }
    }
    return count;
}
// max no. of cake pieces: 0 cuts=>1 piece, 1 cut=2 , 2 cuts=4, 3 cuts=7
// pattern: 1 ,2 , 4, 7, 11, 16
int maxCuts(int n){
    int pSum=1;
    for(int i=0;i<=n;i++){
        pSum+=i;
    }
    return pSum;
}
int main(){
    int n;
    cout<<"Enter the number of elmnts";
    cin>>n;
    int *a=new int[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    superiorelmnt(a,n);
    delete[] a;
}