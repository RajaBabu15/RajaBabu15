#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool fun1(const pair<int,pair<int,int>> &x, const pair<int,pair<int,int>> &y)
{
    return x.second.second>y.second.second;
}

bool fun2(const pair<int,pair<int,int>> &x, const pair<int,pair<int,int>> &y)
{
    return x.second.first>y.second.first;
}

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    vector<pair<int,pair<int,int>>> vect(n);
        for(int i=0;i<n;i++){
            vect[i].first=i+1;
            cin>>vect[i].second.first;
        }
        for(int i=0;i<n;i++){
            cin>>vect[i].second.second;
        }
        sort(vect.begin(),vect.end(),fun1);
        sort(vect.begin(),vect.end(),fun2);
                    cout<<vect[0].first<<endl;
	}
	return 0;
}
