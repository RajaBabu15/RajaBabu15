#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    int arr[n];
	    for(int i=0;i<n;i++) cin>>arr[i];
        sort(arr,arr+n);
	    int mini = INT_MAX;
	    for(int i=0;i<n;i++)
	    for(int j=0;j<n;j++) 
        for(int k=0;k<n;k++){
            if(i!=j&&j!=k&&k!=i)
	    if(abs(arr[i]+arr[j]-2*arr[k])<mini)
	    mini= abs(arr[i]+arr[j]-2*arr[j]);
	    }
	    cout<<3*mini<<endl;
	    
	}
	return 0;
}
