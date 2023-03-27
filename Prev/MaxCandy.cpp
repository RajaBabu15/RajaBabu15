#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int code(int arr[],int n){
    if(n<=0) return 0;
    
    int cond1 = arr[0]+code(arr+2,n-2);
    int cond2 = code(arr+1,n-1);
    
    int ans = max(cond1,cond2);
    return ans;
}

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    int arr[100];
	    for(int i=0;i<n;i++){
	        cin>>arr[i];
	    }
	    cout<<code(arr,n)<<endl;
	}
	return 0;
}
