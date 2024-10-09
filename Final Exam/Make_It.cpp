#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll input;
ll dp[100005];
ll recur(ll n)
{
    if (n > input)
    {
        return 0;
    }

    if (n == input)
    {
        return 1;
    }
    if(dp[n] != -1)
    {
        return dp[n];
    }

    return dp[n]= recur(n + 3) || recur(n * 2);
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> input;
        memset(dp, -1, sizeof(dp));
        ll flag = recur(1);

        if (flag)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
}