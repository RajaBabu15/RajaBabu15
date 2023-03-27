#include <bits/stdc++.h>

using namespace std;

int getLCSLengthRecursion(string s1,string s2){
    if(s1.at(0)=='\0'||s2.at(0)=='\0')
        return 0;
    if(s1.at(0)==s2.at(0))
        return 1+getLCSLengthRecursion(s1.substr(1),s2.substr(1));
    else
        return max(getLCSLengthRecursion(s1.substr(1),s2),getLCSLengthRecursion(s1,s2.substr(1)));
}

int getLCSLengthMem(string s1,string s2){
    int arr[s1.size()+1][s2.size()+1];
    for(int i=0;i<s1.size()+1;i++){
        arr[i][s2.size()]=0;
    }
    for(int i=0;i<s2.size()+1;i++){
        arr[s1.size()][i]=0;
    }
    for(int i=s1.size()-1;i>=0;i--){
        for(int j=s2.size()-1;j>=0;j--){
            if(s1.at(i)==s2.at(j))
                arr[i][j]=1+arr[i+1][j+1];
            else 
                arr[i][j]=max(arr[i+1][j],arr[i][j+1]);
        }
    }
    return arr[0][0];
}

int getLCSLengthDP(string s1,string s2){
    int arr[s1.size()][s2.size()];
    for(int i=0;i<s2.size();i++){
        arr[0][i] = (s1.at(0)==s2.at(i))?1:0;
    }
    for(int i=1;i<s1.size();i++){
        arr[i][0] = (s1.at(i)==s2.at(0))?1:0;
    }

    for(int i=1;i<s1.size();i++){
        for(int j=1;j<s2.size();j++){
            if(s1.at(i)==s2.at(j))
                arr[i][j]=1+arr[i-1][j-1];
            else 
                arr[i][j]=max(arr[i-1][j],arr[i][j-1]);
        }
    } 
    return arr[s1.size()-1][s2.size()-1];
}

int getLengthLCS(string s1, string s2){
    int lengthRecur = getLCSLengthRecursion(s1,s2);
    int lengthMem = getLCSLengthMem(s1,s2);
    int lengthDP = getLCSLengthDP(s1,s2);
    if(lengthMem== lengthDP&&lengthDP==lengthRecur) return lengthDP;
    else throw invalid_argument( "received unequal value" );
}

int main(){
    string s1= "strong";
    string s2 = "stone";
    int length = getLengthLCS(s1,s2);
    cout<<length<<endl;
    return 0;
}