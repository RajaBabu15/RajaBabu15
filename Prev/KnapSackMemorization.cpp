
#include <cstring>
#include <iostream>
using namespace std;

#include <bits/stdc++.h>
using namespace std;

int knapsackMem(int *weights, int *values, int n, int maxWeight, int **output)
{
    if (n == 0 || maxWeight == 0)
        return 0;

    if (output[n][maxWeight] != -1)
        return output[n][maxWeight];
    // Recursive Case
    if (weights[0] > maxWeight)
    {
        int y = knapsackMem(weights + 1, values + 1, n - 1, maxWeight, output);
        output[n][maxWeight] = y;
        return y;
    }

    int x = knapsackMem(weights + 1, values + 1, n - 1, maxWeight - weights[0], output) + values[0];
    int y = knapsackMem(weights + 1, values + 1, n - 1, maxWeight, output);
    output[n][maxWeight] = max(x, y);
    return max(x, y);
}
int knapsack(int *weight, int *value, int n, int maxWeight)
{
    // Write your code here
    int **dp;
    dp = new int *[n];
    for (int i = 0; i < n; i++)
        dp[i] = new int[maxWeight + 1];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < maxWeight + 1; j++)
            dp[i][j] = -1;
    return knapsackMem(weight, value, n, maxWeight, dp);
}

int main()
{
    int n;
    cin >> n;
    int *wt = new int[n];
    int *val = new int[n];

    for (int i = 0; i < n; i++)
    {
        cin >> wt[i];
    }

    for (int j = 0; j < n; j++)
    {
        cin >> val[j];
    }

    int w;
    cin >> w;

    cout << knapsack(wt, val, n, w) << "\n";

    delete[] wt;
    delete[] val;
}