#include<bits/stdc++.h>
using namespace std;

bool get(vector<int> &vect,int n,int sum,int max){
    if(sum==0&&n==0) return true;
    if(sum==0&&n!=0) return false;
    if(sum!=0&&n==0) return false;
    if(n<0||sum<0) return false;

    for(int i=max;i>=1;i--){
        vect.push_back(i);
        bool smallOutput = get(vect,n-1,sum-i,i);
        if(smallOutput)
            return true;
        else{
            vect.pop_back();
        }
    }
    return false;
}


int main(){
    int t;
    cin>>t;
    while(t--){
        int n,s,r;
        cin>>n>>s>>r;
        vector<int> vect;
        vect.push_back(s-r);
        get(vect,n-1,r,s-r);
        // int len = vect.size();
        for(auto i: vect) cout<<i<<" ";
    }
    return 0;
}