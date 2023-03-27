#include <bits/stdc++.h>
using namespace std;

int minCount(int n)
{
	//Write your code here
    
    int* ans=new int[n+1];
    cout<<"Here"<<endl;
    for(int i=0;i<=n;i++){ i=-1;
                          cout<<i<<endl;
                          
                         }
    ans[0]=0;
    ans[1]=1;
    ans[2]=1;
    ans[3]=1;
    ans[4]=2;
    ans[5]=2;
    if(n<=5) return ans[5];
    for(int i=6;i<=n;i++){
        int j=1;
        int mini=INT_MAX;
        while(i-j*j>=0){
            mini=min(ans[i-j*j],mini);
            j++;
        }
        ans[n]=1+mini;
    }
    return ans[n];
}
int main()
{
	int n;
	cin >> n;
	cout << minCount(n);
}