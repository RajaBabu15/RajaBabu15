#include<iostream>
using namespace std;
void setZeros(int arr[],int n){
    for(int i=0;i<n;i++){
        arr[i]=0;
    }
}
void doTask(int n){
    int arr[n];
    setZeros(arr,n);
    int max=n-1;
    for(int i=max;i>=1;i--){
        
    }
}
int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int n;
        cin>>n;
        doTask(n);
    }
    return 0;
}