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
int main(){
    printNumber(10);
    cout<<endl<<"Printing numbers 1 to 10: ";
    print2(1);
    cout<<endl<<"Factorial of 5 using recursion: "<<fact(5);

    return 0;
}