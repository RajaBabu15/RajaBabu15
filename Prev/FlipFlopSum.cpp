#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> vect(n,0);
        int minus=0;
        bool flag=false,trigger=false;

        for(auto &ele : vect){
            cin>>ele;
            if(!trigger&flag&ele<0) trigger=true;
            if(ele<0) {
                minus++;
                flag = true;
            }
            else flag=false;

        }
        // cout<<trigger<<minus<<endl;
        if(minus==0) cout<<n-4;
        else if (minus ==1) cout<<n-2;
        else if (minus==2&&trigger) cout<<n;
        else if(minus==2) cout<<n-4;
        else if (minus >=3 && trigger) cout<<n-2*minus+4    ;
        else cout<<n-minus*2;
        cout<<endl;
    }
    return 0;
}