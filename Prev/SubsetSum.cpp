/* Time complexity : O(2^N) Space complexity : O(N) where N is the size of input array */
#include <bits/stdc++.h>
using namespace std;
int subsetCount(int arr[], int n, int index, int target)
{
    if (index == n)
    {
        if (target == 0)
        {
            return 1;
        }
        else
            return 0;
    }
    int count = 0;
    if (target - arr[index] >= 0)
    {
        count += subsetCount(arr, n, index + 1, target - arr[index]);
    }
    count += subsetCount(arr, n, index + 1, target);
    return count;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        cout << subsetCount(arr, n, 0, k) << endl;
    }
}