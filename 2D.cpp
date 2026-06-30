#include <iostream>
using namespace std;
int main(){
    int r;
    cout<<"Enter the number of rows: ";
    cin>>r;
    int c;
    cout<<"Enter the number of columns: ";
    cin>>c;
    cout<<"Enter elmnts of array: ";
    int a[r][c];
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cin>>a[i][j];
        }
    }
    cout<<"elmnts of array: ";

  for(int i=0;i<r;i++){
        for(int j=0;j<c;j++)
        cout<<a[i][j]<<" ";
        cout<<endl;
    }
    cout<<endl<<"Elmnts of array at even columns: ";
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j+=2)
        cout<<a[i][j]<<" ";
        cout<<endl;
    }
    cout<<endl<<"Elmnts at odd columns: ";
     for(int i=0;i<r;i++){
        for(int j=1;j<c;j+=2)
        cout<<a[i][j]<<" ";
        cout<<endl;
    }
}