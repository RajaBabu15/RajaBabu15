#include<iostream>

using namespace std;

void print(long long *arr,int n){
    long long sum = 0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
        // cout<<arr[i]<<" ";
    }

    cout<<2022*sum<<endl;
}



void perform (long long *arr,int n) {
    long long l=INT_MIN,li=-1,sl=INT_MIN,sli=-1;
    for(int i=0;i<n;i++){
        if(arr[i]>l)  {l=arr[i]; li = i;}
        if(arr[i]>sl&&i!=li) {
            sl=arr[i];
            sli=i;
        }

    }

    arr[li]=l*sl;
    arr[sl]=1;
}


void test() {
    int n;
    cin>>n;
    long long *arr = new long long[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    perform(arr,n);

    print(arr,n);
}




int main(){
    int t=1;
    cin>>t;
    while (t-->0)
    {
        test();
    }
    

    return 0;
}