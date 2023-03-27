#include<iostream>
using namespace std;


void doTest(){
    int n;
    cin>>n;
    char ch[n+1];
    for(int i=0;i<n+1;i++){
        ch[i]='\0';
    }
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    string repl;
    cin>>repl;
    for(int i=0;i<n;i++)
        for(int j=i;j<n;j++)
            if(arr[j]==arr[i]&&ch[j]=='\0')
                ch[j]=repl.at(i);
    string str = string(ch);
    if(str.compare(repl)==0) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;        
}

int main(){
    int t;
    cin>>t;
    for(int i=1;i<=t;i++){
        doTest();
    }
    return 0;
}