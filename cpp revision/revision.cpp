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
    char grade='A';
    switch(grade){
        case 'A':
        cout<<"Excellent";
        break;
        case 'B':
        cout<<"okay";
        break;
        case 'C':
        cout<<"Avg";
        break;
        default:
        cout<<"Invalid";
    }
    return 0;
}