#include <iostream>
#include <vector>
using namespace std;
bool divide(vector<int>arr){
    int total=0;
    for(int i:arr)
    total+=i;

    int prefix=0;
    for(int i=0;i<arr.size()-1;i++){
        prefix+=arr[i];
        int ans=total-prefix;
        if(ans==prefix) return true;
    }
    return false;
}
int main(){
    cout<<"Enter number of elmnts of array";
    int n;
    cin>>n;
    vector<int>a(n);
    cout<<"enter elmnts in array: ";
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    if(divide(a))
    cout<<"array can be divided into 2 equal sums";
    else
    cout<<"Array cant be divided into 2 equal sums";
    return 0;
}