#include <iostream>
using namespace std;
void sum(int b[][3]){
    for(int i=0;i<3;i++){
        int sum=0;
        for(int j=0;j<3;j++)
        sum+=b[i][j];
        cout<<sum<<" ";
    }
}
int main(){
//     int r;
//     cout<<"Enter the number of rows: ";
//     cin>>r;
//     int c;
//     cout<<"Enter the number of columns: ";
//     cin>>c;
//     cout<<"Enter elmnts of array: ";
//     int a[r][c];
//     for(int i=0;i<r;i++){
//         for(int j=0;j<c;j++){
//             cin>>a[i][j];
//         }
//     }
//     cout<<"elmnts of array: ";

//   for(int i=0;i<r;i++){
//         for(int j=0;j<c;j++)
//         cout<<a[i][j]<<" ";
//         cout<<endl;
//     }
//     cout<<endl<<"Elmnts of array at even columns: ";
//     for(int i=0;i<r;i++){
//         for(int j=0;j<c;j+=2)
//         cout<<a[i][j]<<" ";
//         cout<<endl;
//     }
//     cout<<endl<<"Elmnts at odd columns: ";
//      for(int i=0;i<r;i++){
//         for(int j=1;j<c;j+=2)
//         cout<<a[i][j]<<" ";
//         cout<<endl;
    // }
    int b[3][3]={1,2,3,4,5,6,7,8,9};
    sum(b);
}