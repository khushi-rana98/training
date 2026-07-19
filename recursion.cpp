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
// fibonacci series using recursion
int fib(int n){
    if(n==0) return 0;
    if(n==1) return 1;
    return fib(n-1)+fib(n-2);

}
// nth staircase problem using recursion
int findways(int n){
    if(n==0) return 1;
    if(n==1) return 1;
    if(n==2) return 2;
    return findways(n-1)+findways(n-2);
}
// find gcd of 2 numbers using recursion--using an algorthm called euclidean algorithm
// remember gcd(a,b)= gcd(b,a%b) gcd(a,0)=a
int gcd(int a, int b) {
      if(b==0) return a;
      return gcd(b,a%b);
        
    }
// head recursion: work happens after the recursive call
//tail recursion: work happens before the recursive call

// sum of elmnts of array using recursion
int sumOfElements(int arr[], int n, int index){
    if(index==n) return 0;
    return arr[index]+sumOfElements(arr, n, index+1);
}

// print elmnts of array both reverse and forward using recursion
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
// recursion on strings
// count vowels
int countVowels(string st, int index, int size){
    if(index==size) return 0;
    if(st[index]=='a'|| st[index]=='e'|| st[index]=='i'|| st[index]=='o'|| st[index]=='u')
    return 1+countVowels(st,index+1,size);
    return countVowels(st,index+1,size);
}
// reverse a string using recursion
void reverseString(string &st, int start, int end){
    if(start>=end) return;
    swap(st[start], st[end]);
    reverseString(st, start+1, end-1);
}
// print the reverse of a string using recursion
void printReverse(string st, int index, int size){
    if(index==size) return;
    printReverse(st, index+1,size);
    cout<<st[index];
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