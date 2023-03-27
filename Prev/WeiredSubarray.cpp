#include <iostream>
#include <vector>
using namespace std;

bool isWired(vector<int> vec){
    bool  flag= false;
    int counter=0;
    for(int i=0;i<vec.size()-1;i++){
        if(vec[i]<=vec[i+1]) continue;
        else{
            if(-vec[i]<vec[i+1]) counter++;
            else break;
        }
    }
    if(counter==1) flag=true;
    return flag;
}

pair<int,vector<vector<int>>> noWeirdSubArrays(vector<int> vect){
    vector<int> cpy(vect.size()-1);
    copy(vect.begin()+1,vect.begin()+vect.size()-1,vect.begin());
    pair<int,vector<vector<int>>> p = noWeirdSubArrays(cpy);
    int no = p.first;
    vector<vector<int>> vecs=p.second;
    for(int i=0;i<vecs.size();i++){
        vector<int> vec = vecs[i];
        vec.push_back(vect[0]);
        if(isWired(vec)) no++;
    }
    p.first=no;
    p.second=vecs;
    return p;
}

int main() {
	// your code goes here
	int  t;
	cin>>t;
	for(int i=0;i<t;i++){
	    int N;
	    cin>>N;
	    vector<int> vect;
	    for(int j=0;j<N;j++){
	        int tmp;
	        cin>>tmp;
	        vect.push_back(tmp);
	    }
	    cout<<noWeirdSubArrays(vect).first;
	}
	return 0;
}
