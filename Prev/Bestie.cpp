#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b)
{
    if (a == 0 || b == 0)
        return 0;
    else if (a == b)
        return a;
    else if (a > b)
        return gcd(a - b, b);
    else
        return gcd(a, b - a);
}

int frontGCD(int arr[20], int n)
{
    int cost = 0;
    for (int i = 0; i < n; i++)
    {
        if (gcd(arr[i], i + 1) != arr[i])
        {
            cost += n - i;
            arr[i] = gcd(arr[i], i + 1);
            if (arr[i] == 1)
                break;
            i--;
        }
        else{
            cost+=n-i;
        }
    }
    return cost;
}

int backGCD(int arr[20], int n)
{
    int cost = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        if (gcd(arr[i], i + 1) != arr[i])
        {
            cost += n - i;
            arr[i] = gcd(arr[i], i + 1);
            if (arr[i] == 1)
                break;
            i++;
        }
    }
    return cost;
}

void doTest(int arr[], int n)
{
    cout << min(frontGCD(arr, n), backGCD(arr, n)) << endl;
}

int main()
{
    cout<<gcd(6,2);
    int t;
    cin >> t;
    int arr[20];
    for (int i = 0; i < t; i++)
    {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        doTest(arr, n);
    }
    return 0;
}