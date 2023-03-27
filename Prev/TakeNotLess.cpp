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
	    int f= 0;
	    for(int i=n-1;i<=0&&arr[i]==arr[n-1];i--) f++;
	    if(f%2==0) cout<<"Zenyk"<<endl;
	    else cout<<"Marichka"<<endl;
	}
	return 0;
}
