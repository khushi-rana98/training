#include <iostream>
using namespace std;
#include <vector>
int main(){
    vector<int>a;
    a.push_back(5);
    a.push_back(2);
    a.push_back(5);
    a.push_back(2);
    a.push_back(5);
  
    cout<<"elmnts in vector are: ";
    for(int i:a){
        cout<<i<<" ";
    }
    cout<<endl;

    cout<<"operation 2:"<<endl;
    for(int i:a){
        a.pop_back();
    }
   if(a.empty()){
    cout<<"array is empty"<<endl;
   }
   
}
// void swap(int &a, int &b){
//     int temp=a;
//     a=b;
//     b=temp;
// }
// void sortColors(int arr[], int n){
//     int low=0;
//     int high=n-1;
//     int mid=0;
//     while(mid<=high){
//         if(arr[mid]==2){
//             swap(arr[mid],arr[high]);
//             high--;
//         }
//         else if(arr[mid]==0){
//             swap(arr[low],arr[mid]);
//             low++;
//             mid++;
//         }
//         else{
//             mid++;
//         }
//     }
// }
// int main(){
    
//     int n;
//     cout<<"Enter the number: ";
//     cin>>n;
//     int arr[n];
//     cout<<"Enter elmnts: ";
//     for(int i=0;i<n;i++){
//         cin>>arr[i];
//     }
//     sortColors(arr,n);
//     cout<<"array after sorting: ";
//     for(int i=0;i<n;i++){
//         cout<<arr[i]<<" ";
//     }
//     return 0;
// }