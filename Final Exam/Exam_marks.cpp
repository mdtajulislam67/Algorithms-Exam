#include <bits/stdc++.h>
using namespace std;

int dp[1005][1005];

bool checkSum(int n, int target, int arr[])
{
    if (n == 0)
    {
        if (target == 0)
            return true;
        else
            return false;
    }
    if (dp[n][target] != -1)
        return dp[n][target];

    if (arr[n - 1] <= target)
    {
        bool pick = checkSum(n - 1, target - arr[n - 1], arr);
        bool noPick = checkSum(n - 1, target, arr);
        return dp[n][target] = pick || noPick;
    }
    else
    {

        return dp[n][target] = checkSum(n - 1, target, arr);
    }
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        memset(dp, -1, sizeof(dp));

        int marks[1000];
        for (int i = 0; i < n; i++)
        {
            cin >> marks[i];
        }
        int target = 1000 - m;
        if (target < 0)
        {
            cout << "NO" << endl;
            continue;
        }
        if (checkSum(n, target, marks))
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}