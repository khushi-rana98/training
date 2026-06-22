#include <iostream>
using namespace std;
int main(){
    int age;
    cout<<"Enter the age";
    // cout<<age; // this variable initialzes wd garbage value
    // static int age2; //static variable by default initialize wd 0
    // cout<<endl<<age2;
    cin>>age;
    int num;
    cout<<"ENter the number";
    cin>>num;
    if(age>=18 && num>=10)
    cout<<"Exam will conduct";
    else
    cout<<"no surity";
    return 0;
}