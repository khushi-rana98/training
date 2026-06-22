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
int countFactors(int num){
    int count=0;
    for(int i=1;i*i<=num;i++){
       if(num%i==0){
        if(i==num/i)
        count+=1;
        else
        count+=2;
       }

    }
    return count;
}
int main(){
    cout<<"hey";
    // prime check
    int n;
    cin>>n;
    if(isPrime(n))
    cout<<n<<" is a prime number";
    cout<<endl<<"Enter the number to count the factors of: ";
    int num;
    cin>>num;
    if(countFactors(num))
    cout<<"number of factors: "<<countFactors<<endl;
    else
    cout<<"NO factors";

    return 0;
}