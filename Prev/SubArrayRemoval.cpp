
#include <iostream>
#include<vector>
using namespace std;

void doTask(string str,int N){
    // vector<pair<char,int>> vec;
    // char ch=str[0];
    // int count=1;
    // for(int i=1;i<N;i++){
    //     if(str[i]==ch) count++;
    //     else{
    //         pair<char,int> p;
    //         p.first= ch;
    //         p.second= count;
    //         vec.push_back(p);
    //         ch=str[i];
    //         count=1;
    //     }
    // }
    // pair<char,int> p=pair<char,int>(ch,count);
    // vec.push_back(p);
    // int ans=0;
    // char prev='\0';
    // while(vec.size()>0){
    //     pair<char,int> p=vec.back();
    //     vec.pop_back();
    //     if(p.first=='1'&&p.second%2!=0)
    //     { 
    //         ans++;
    //         prev='0';
    //     }
    //     else if(p.first=='1'&&p.second%2==0) {
    //         pair<char,int> b=vec.back();
    //         if(prev!='0'&&b.second>1) { ans++; prev='0';}
    //         else{ ans++; prev='\0';}
    //     }
    //     if(p.first=='0') prev='0';
    // }
    // cout<<ans<<endl;
    int z=0;
    for(int i=0;i<N;i++){
        if(str[i]=='0') z++;
    }
    int o=N-z;
    if(o==z) cout<<o<<endl;
    else if(z>o){
        cout<<o<<endl;
    }
    else{
        int ans=z;
        o-=z;
        ans+=(o%3);
        cout<<ans<<endl;
    }
}


int main() {
	// your code goes here
	int t;
	cin>>t;
	for(int i=0;i<t;i++){
	    int N;
	    cin>>N;
        string str="";
        for(int j=0;j<N;j++){
            int i;
            cin>>i;
            str+=to_string(i);
        }
	    doTask(str,N);
	}
	return 0;
}

