#include <bits/stdc++.h>
using namespace std;

int main(){
    string pi_val = "314159265358979323846264338327";
    int t;
    cin>>t;
    while(t--){
        string inp;
        cin>>inp;
        int counter=0;
        while(counter<inp.length()){
            if(inp.at(counter)!=pi_val.at(counter))
                break;
            else 
                counter++;
        }
        cout<<max(0,counter)<<endl;
    }
    return 0;
}