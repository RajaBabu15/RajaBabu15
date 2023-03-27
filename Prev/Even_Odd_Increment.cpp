#include<iostream>
using namespace std;

void doQuerry(int arr[],int size){
    int op,xj;
    long long sum=0;
    cin>>op>>xj;
    if(op==0){
        for(int i=0;i<size;i++){
            if(arr[i]%2==0) sum+=(arr[i]+xj);
            else sum+=arr[i];
        }
    }
    else if(op==1){
        for(int i=0;i<size;i++){
            if(arr[i]%2!=0) sum+=(arr[i]+xj);
            else sum+=arr[i];
        }
    }
    
    cout<<sum<<endl;
}

void doTest(){
    int n,q;
    cin>>n>>q;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    for(int i=0;i<q;i++){
        doQuerry(arr,n);
    }
}

int main(){
    int t;
    cin>>t;
    for(int i=1;i<=t;i++){
        doTest();
    }
    return 0;
}