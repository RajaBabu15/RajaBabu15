#include <iostream>
#include<bits/stdc++.h>
using namespace std;

bool comb(int sum,int n,int* vect,int i){
    if(sum==n) return true;
    else if(sum>n) return false;
    if(i==0) return false;
    if(vect[0]%2==0){
        for(int i=0;i<n;i+=2){
            bool smallOutput = comb(sum+i,n,vect+1,i-1);
            if(smallOutput) return true;
        }
    }
    else {
        for(int i=1;i<n;i+=2){
            bool smallOutput = comb(sum+i,n,vect+1,i-1);
            if(smallOutput) return true;
        }
    }
    return false;
}

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    int vect[n];
	    for(int i=0;i<n;i++) cin>>vect[i];
	    cout<<(comb(0,n,vect,n)?"YES":"NO")<<endl;
	}
	return 0;
}
