#include <iostream>
using namespace std;

int dp[12];

int DP(int x)
{
    if (x == 1) return 1;
    if (x == 2) return 2;
    if (x == 3) return 4;
    if (dp[x] != 0) return dp[x];
    return dp[x] = DP(x - 1) + DP(x - 2) + DP(x - 3);
}

int main()
{
    int T, n;
    cin >> T;
    for (int i = 0; i < T; ++i)
    {
        cin >> n;
        cout << DP(n) << endl;
    }

    return 0;
}