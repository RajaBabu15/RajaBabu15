#include <iostream>
#include <cstring>
#include <unordered_map>
using namespace std;

int editDistance_Mem(string s1, string s2,int ** output) {
	// Write your code here
    
    //Base Case
    if(s1.size()==0&&s2.size()==0) return 0 ;
    if(s1.size()==0) return s2.size();
    if(s2.size()==0) return s1.size();
    if(s1.compare(s2)==0)
        return 0;
    
    int m=s1.size();
    int n=s2.size();
    if(output[m][n]!=-1)
        return output[m][n];
    
    if(s1[0]==s2[0])
        return editDistance_Mem(s1.substr(1),s2.substr(1),output);
    else {
        int d=editDistance_Mem(s1,s2.substr(1),output);
        int r=editDistance_Mem(s1,s1[0]+(s2.substr(1)),output);
        int i=editDistance_Mem(s1,s1[0]+s2,output);
        int ans=1+min(d,min(r,i));
        
        //save The output
        output[m][n]=-1;
        
        return ans;
    }
}
int editDistance(string s1,string s2){
    int m=s1.size();
    int n=s2.size();
    int **output = new int*[m+1];
    for(int i=0;i<=m;i++){
        output[i]=new int[n+1];
        for(int j=0;j<=n;j++)
            output[i][j]=-1;
    }
    editDistance_Mem(s1,s2,output);
    return output[m][n];
}

int main()
{
	string s1;
	string s2;

	cin >> s1;
	cin >> s2;

	cout << editDistance(s1, s2) << endl;
}