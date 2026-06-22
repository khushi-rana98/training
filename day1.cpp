#include <iostream>
using namespace std;
// question 1: prime check
bool isPrime(int num){
    if(num<2) return false;
    for(int i=2;i*i<=num;i++){
        if(num%i==0) return false;
    }
    return true;
}
int main(){
    cout<<"hey";
    // prime check
    int n;
    cin>>n;
    if(isPrime(n))
    cout<<n<<" is a prime number";
    return 0;
}