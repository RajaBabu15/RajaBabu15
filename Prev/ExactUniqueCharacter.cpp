#include <iostream>
#include <string>
using namespace std;

#include<unordered_map>
string uniqueChar(string str) {
	// Write your code here
    string unique="";
    unordered_map<char,int> seen;
    for(int i=0;str[i]!='\0';i++){
        if(seen.count(str[i])>0) continue;
        else{
            unique+=str[i];
            seen[str[i]]=0;
        }
    }
    return unique;
}

int main() {
    string str;
    cin >> str;
    cout << uniqueChar(str);
}