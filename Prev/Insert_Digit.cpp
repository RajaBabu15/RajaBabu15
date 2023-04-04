#include<bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        long long num;
        int d;
        int len;
        cin>>len>>d>>num;
        long long max_val = -1;
        for(int i=0;i<=len;i++){
            long long a = powl(10,i);
            long long b = num%a;
            long long c= num/a;
            long long var = c*a*10+d*a+b;
            if(var>max_val) max_val=var;
        }
        cout<<max_val<<endl;
    }
    return 0;
}