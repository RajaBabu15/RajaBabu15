#include<iostream>
using namespace std;

void doTask(string str,int n){
    bool flag=false;
    int q=0;
    for(int i=0;i<n;i++){
        if(str[i]=='Q')  { flag=false; q++;}
        if(str[i]=='A') {flag=true; q--;} 
    }
    if(flag&&q<=0) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}

int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int n;
        cin>>n;
        string str;
        cin>>str;
        doTask(str,n);

    }
    return 0;
}