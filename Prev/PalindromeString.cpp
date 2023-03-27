#include<string>
#include<iostream>
using namespace std;
string getString(char arr[]) { 
    int size = sizeof(&arr);
    string s = "";
    for(int i=0;i<size;i++){
        s+=arr[i];
    }
    return s;
}

string reverse(string str) {
  int len = str.length();
  int n = len;
  string rev="";
  while (n--)
    rev+=str[n];
    return rev;
}


bool checkPalindrome(char input[]) {
    // Write your code here
    string s = getString(input);
    string rev = reverse(s);
    cout<<s<<rev<<endl;
    return (s.compare(rev)==0);
}


#include <iostream>
using namespace std;

int main() {
    char input[50];
    cin >> input;
    
    if(checkPalindrome(input)) {
        cout << "true" << endl;
    }
    else {
        cout << "false" << endl;
    }
}