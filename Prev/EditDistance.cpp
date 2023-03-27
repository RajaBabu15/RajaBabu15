#include <cstring>
#include <iostream>
using namespace std;

int editDistance(string s1, string s2) {
	// Write your code here
    if(s1.compare(s2)==0)
        return 0;
    if(s1[0]==s2[0])
        return editDistance(s1.substr(1),s2.substr(1));
    else {
        int d=editDistance(s1,s2.substr(1));
        int r=editDistance(s1,s1[0]+(s2.substr(1)));
        int i=editDistance(s1,s1[0]+s2);
        int ans=min(d,min(r,i));
        return ans;
    }
}



int main() {
    string s1;
    string s2;

    cin >> s1;
    cin >> s2;

    cout << editDistance(s1, s2);
}