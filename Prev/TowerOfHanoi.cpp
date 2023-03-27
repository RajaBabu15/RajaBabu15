#include <cstdlib>
#include <string>
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

#include<vector>
using namespace std;

void towerOfHanoiHelper(int n,int start,int end,int aux, vector<vector<int>> &dir) {
    if(n==0) return ;
    towerOfHanoiHelper(n-1, start,aux,end,dir);
    vector<int> vect;
    vect.clear();
    vect.push_back(start);
    vect.push_back(end);
    dir.push_back(vect);
    towerOfHanoiHelper(n-1,aux,end,start,dir);
}

vector<vector<int>> towerOfHanoi(int n,int start=1,int end=3, int aux=2)
{
    //    Write your code here.
    vector<vector<int>> dir;
    dir.clear();
    towerOfHanoiHelper(n,1,3,2,dir);
    return dir;

}

bool checker(vector<vector<int>> &v, int n)
{
    vector<int> a[3];
    //  push all the disks to the first rod.
    for (int i = n; i >= 1; i--)
    {
        a[0].push_back(i);
    }

    int sz = n;
    //    If there are more than 2^n -1 moves return false.
    if (v.size() >= (1 << n))
    {
        cout<<"No of moves exceeded"<<endl;
        return false;
    }

    for (int i = 0; i < v.size(); i++)
    {
        
        
        //    if one move has more than 3 integers return false
        if (v[i].size() != 2)
        {
            cout<<"Using more than 2 disks in one move"<<endl;
            return false;
        }

        int to = v[i][1];
        int from = v[i][0];

        //  If Rod number lies out of range return false.
        if (to <= 0 or from <= 0)
        {
            cout<<"Invalid rod number "<<endl;

            return false;
        }

        //  If Rod number lies out of range return false.
        if (to > 3 or from > 3)
        {
            cout<<"Invalid rod number "<<endl;

            return false;
        }

        //  0 based indexing
        to--;
        from--;

        //    If there is no disk on the rod return false.
        if (a[from].empty())
        {
            cout<<"Removing disk from empty rod"<<endl;
            return false;
        }

        int last = a[from].back();
        a[from].pop_back();

        //    If the disk can be placed on the required rod.
        if (a[to].empty() or a[to].back() > last)
        {
            a[to].push_back(last);
        }
        //    Return false if the disk is placed on a smaller disk
        else
        {
            cout<<"Placing a larger disk on a smaller disk"<<endl;
            return false;
        }
    }

    //    Return true if rod 2 or rod 3 has N disks.
    return (a[1].size() == n or a[2].size() == n);
}

class Runner
{
    int t;
    vector<int> arr;

public:
    void takeInput()
    {

        cin >> t;
        arr.resize(t);
        for (int tc = 0; tc < t; tc++)
        {
            
            cin >> arr[tc];
            
        }
    }

    vector<int> getCopy()
    {
        vector<int> arrCopy = arr;

        return arrCopy;
    }

    void execute()
    {
        vector<int> arrCopy = arr;
        for (int i = 0; i < t; i++)
        {
            vector<vector<int>> ans = towerOfHanoi(arrCopy[i]);
        }
    }

    void executeAndPrintOutput()
    {
        for (int i = 0; i < t; i++)
        {
            int temp=arr[i];
            vector<vector<int>> ans = towerOfHanoi(arr[i]);

            if (checker(ans, temp))
            {
                cout << 1 << endl;
            }
            else
            {
                cout << 0 << endl;
            }
        }
    }
};

int main()
{

    Runner runner;
    runner.takeInput();
    runner.executeAndPrintOutput();

    return 0;
}