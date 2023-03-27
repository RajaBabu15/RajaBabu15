#include <iostream>
using namespace std;

#include <unordered_map>
int getPairsWithDifferenceK(int *arr, int n, int k)
{
    // Write your code here
    unordered_map<int, int> map;
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (map.count(arr[i] )== 0)
            map[arr[i]] = 1;
        else
            map[arr[i]]++;
    }
    for (int i = 0; i < n; i++)
    {
        if (map[arr[i] - k] > 1)
        {
            count += map[arr[i] - k] - 1;
            map[arr[i] - k] = map[arr[i] - k] - 1;
        }
    }

    return count;
}
int main()
{
    int n;
    cin >> n;

    int *input = new int[n];

    for (int i = 0; i < n; i++)
    {
        cin >> input[i];
    }

    int k;
    cin >> k;

    cout << getPairsWithDifferenceK(input, n, k);

    delete[] input;
}