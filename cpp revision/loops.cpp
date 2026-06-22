#include <iostream>
using namespace std;
int main(){
    cout<<"Pattern priniting"<<endl;
    // for loop
    cout<<"Printing numbers using for loop: ";
    for(int i=2;i<20;i++){
        cout<<i<<" ";
    }
    int x=1;
    cout<<endl<<"printing numbers using whole loop: ";
    while(x<19){
        cout<<x<<" ";
        x+=2;
    }
    cout<<endl<<"Printing the numbers using do while: ";
    int y=3;
    do{
        cout<<y<<" ";
        y+=3;
    }while(y<=30);

}