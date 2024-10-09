#include <bits/stdc++.h>
using namespace std;

bool vis[10][10];
int dis[10][10];

vector<pair<int, int>> d = {{2, 1}, {2, -1}, {-2, 1}, {-2, -1},{1, 2}, {1, -2}, {-1, 2}, {-1, -2}};
int n, m;

bool valid(int i, int j)
{
    if (i < 0 || i >= n || j < 0 || j >= m)
        return false;
    return true;
}
int bfs(int ki, int kj, int qi, int qj)
{
    if( ki==qi && kj==qj)
     {
        return 0;
     }

    memset(vis,false,sizeof(vis));
    memset (dis, -1, sizeof(dis));

    queue<pair<int, int>> q;

    q.push({ki, kj});
    vis[ki][kj] = true;
    dis[ki][kj] = 0;

    while (!q.empty())
    {
        pair<int, int> par = q.front();
        int a = par.first, b = par.second;
        q.pop();
        for (const auto& m : d)
        {
            int ci = a + m.first;
            int cj = b + m.second;
            if (valid(ci, cj) == true && vis[ci][cj] == false)
            {
                vis[ci][cj] = true;
                dis[ci][cj] = dis[a][b] + 1;
                q.push({ci, cj});
            }

            if(ci==qi && cj==qj)
            {
                return dis[ci][cj];
            }
        }

    }
    return -1;
}
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        cin>>n>>m;

        int ki,kj;
        cin>>ki>>kj;

        int qi,qj;
        cin>>qi>>qj;

        int ans = bfs(ki,kj,qi,qj);
        cout<<ans<<endl;
    }
    
    return 0;
}