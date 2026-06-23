#include <iostream>
using namespace std;
void swap(int &a, int &b){
    int temp=a;
    a=b;
    b=temp;
}
void sortColors(int arr[], int n){
    int low=0;
    int high=n-1;
    int mid=0;
    while(mid<=high){
        if(arr[mid]==2){
            swap(arr[mid],arr[high]);
            high--;
        }
        else if(arr[mid]==0){
            swap(arr[low],arr[mid]);
            low++;
            mid++;
        }
        else{
            mid++;
        }
    }
}
int main(){
    
    int n;
    cout<<"Enter the number: ";
    cin>>n;
    int arr[n];
    cout<<"Enter elmnts: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    sortColors(arr,n);
    cout<<"array after sorting: ";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}