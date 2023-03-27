#include <bits/stdc++.h>
using namespace std;

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> vect(n, 0);
        for (int i = 0; i < n; i++)
            cin >> vect[i];
        sort(vect.begin(), vect.end());

        int counter=0;
        while (vect.size() > 0)
        {
            int ptr = vect[0];
            for (int i = 0; i < vect.size(); i++)
            {
                if (vect[i] -1== ptr)
                {
                    ptr = vect[i];
                    vect.erase(vect.begin() + i);
                    i--;
                }
            }
            vect.erase(vect.begin());
            counter++;
        }
        cout<<counter<<endl;
    }
    return 0;
}