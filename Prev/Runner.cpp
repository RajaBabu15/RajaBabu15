#include<vector>
using namespace std;
bool lookGood(vector<int> &a)
{
    bool flag=false;
    for(int i=a.size()-1;i>=0;i--){
        if(a[i]==1) flag=true;
        else if(a[i]==0&&flag) return false;
    }
    return flag;
}
int removeBulbs(vector<int> &a) {
	// Write your code here.
    if(a.size()==0||lookGood(a)) return 0;
    if(a[a.size()]=='1') {
        int back=a.back();
        a.pop_back();
        int val =removeBulbs(a);
        a.push_back(back);
        return val;
    }
    else {
        int back=a.back();
        a.pop_back();
        int yes=removeBulbs(a)+1;
        int no=removeBulbs(a);
        int ans=min(yes,no);
        a.push_back(back);
        return ans;
    }
    return 0;
}