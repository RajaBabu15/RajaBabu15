#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int printSubsequence(string input, string output,int val)
{
    if (input.empty()) {
        if(output.length()>1&&isPalindrome(output)&&val>output.length()){
            return output.length();
        }
        return;
    }
    int a = printSubsequence(input.substr(1), output + input[0],val);
    int b= printSubsequence(input.substr(1), output,val);
    return min(a,b);
}
 

bool isPalindrome(string str)
{
    for (int i = 0; i < str.length() / 2; i++) {
        if (str[i] != str[str.length() -i- 1]) {
            return false;
        }
    }
    return true;
}

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--){
	    int n;
	    string s;
	    cin>>n;
	    cin>>s;
	    vector<string> vect;
	    int vv = printSubsequence(s,"",INT_MAX);
        int vv = n-val(vect);
        if(vv>=0)
	    cout<<vv<<endl;
        else
        cout<<-1<<endl;

	}
	return 0;
}
