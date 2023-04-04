#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int m,pp;
        cin>>pp>>m;
        int p=pp;
        int index=-1;
        int max=INT_MIN;
        while(p--){
            int var;
            cin>>var;
            if(var>max&&var<m){
                max=var;
                index=pp-p;
            }
        }
        cout<<index<<endl;
    }

}