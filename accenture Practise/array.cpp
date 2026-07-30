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