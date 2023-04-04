#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
int exponentMod(int A, int B, int C)
{

    if (A == 0)
        return 0;
    if (B == 0)
        return 1;
    long y;
    if (B % 2 == 0) {
        y = exponentMod(A, B / 2, C);
        y = (y * y) % C;
    }
    else {
        y = A % C;
        y = (y * exponentMod(A, B - 1, C) % C) % C;
    }
    return (int)((y + C) % C);
}
 

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int a, b;
        cin >> a >> b;
        cout << exponentMod(a,b,10)<< endl;
    }
    return 0;
}