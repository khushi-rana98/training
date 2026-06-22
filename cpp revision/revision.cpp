#include <iostream>
using namespace std;
int main(){
        int x,y;
        cout<<endl<<"Enter first number";
        cin>>x;
        cout<<endl<<"ENter second number";
        cin>>y;
        int result=(x>y)?x:y;
        cout<<"Greater value is:"<<result;
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