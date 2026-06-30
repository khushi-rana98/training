#include <iostream>
using namespace std;
void printNumber(int n){
    if(n==0) return;
    cout<<n<<" ";
    printNumber(n-1);
}
void print2(int n){
    if(n==11) return;
    cout<<n<<" ";
    print2(n+1);
}
int fact(int n){
    if(n==0) return 1;
    return n*fact(n-1);
}
int fib(int n){
    if(n==0) return 0;
    if(n==1) return 1;
    return fib(n-1)+fib(n-2);

}
bool linearSearch(int arr[], int n, int key){
    if(n==0) return false; 
    if(arr[0]==key) return true;
    return linearSearch(arr+1, n-1, key);
}
bool binarySearch(int a[], int s, int e, int key){
    if(e<s) return false;
    int mid=s+(e-s)/2;
    if(a[mid]==key) return true;
    else if(a[mid]>key) return binarySearch(a,0,mid-1,key);
    else
    return binarySearch(a,mid+1,e,key);
}
int main(){
    printNumber(10);
    cout<<endl<<"Printing numbers 1 to 10: ";
    print2(1);
    cout<<endl<<"Factorial of 5 using recursion: "<<fact(5);
   
    cout<<endl<<"10th fibonacci term : "<<fib(1);
    int n=5;
    int a[5]={10,20,50,15,23};
    int target=15;
    if(linearSearch(a,n,target))
    cout<<"elmnt found!";
    else
    cout<<"elmnt not found!"<<endl;

    int n2=6;
    int b[6]={3, 2, 43, 21, 56, 43};
    if(binarySearch(b,0,5,43))
    cout<<"elmnt found";
    else
    cout<<"elmnt not found!";

    return 0;
}