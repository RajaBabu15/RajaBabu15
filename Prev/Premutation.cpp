#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int arr[n][n-1];
        for(int i=0;i<n;i++){
            for(int j=0;j<n-1;j++){
                cin>>arr[i][j];
            }
        }
        int x=arr[0][0],xc=0,y=INT_MAX,yc=0;
        for(int i=0;i<n;i++){
            if(arr[i][0]==x) xc++;
            else {
                y=arr[i][0];
                yc++;
            } 
        }
        int sea;
        if(xc>yc){
            sea = y;
            cout<<x<<" ";
        }
        else {
            sea = x;
            cout<<y<<" ";
        }
        for(int j=1;j<n-1;j++){
            for(int i=0;i<n;i++){
                // cout<<i<<j<<arr[i][j]<<sea<<endl;
                if(arr[i][j]!=sea){
                    cout<<sea<<" ";
                    sea = arr[i][j];
                    break;
                }
            }
        }
        cout<<sea<<endl;
    }
    return 0;
}