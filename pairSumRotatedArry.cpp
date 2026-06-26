#include <iostream>
using namespace std;
bool pairSum(vector<int>arr, int target){

}
int main(){
    int n;
    cout<<"ENter number of elmnts";
   vector<int>a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    cout<<"enter k: ";
    int k;
    cin>>k;
    if(pairSum(a,k))
    cout<<"yes. the pair sum exist for this";
    else
    cout<<"NO pair sum does nt exist for this array!";
    delete[] a;
    return 0;
}