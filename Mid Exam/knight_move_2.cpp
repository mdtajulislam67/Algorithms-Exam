#include <bits/stdc++.h>
using namespace std;

bool vis[100][100];

int n, m;

vector<pair<int, int>> d = {{2, 1}, {2, -1}, {-2, 1}, {-2, -1},{1, 2}, {1, -2}, {-1, 2}, {-1, -2}};

bool valid(int i, int j)
{
    return i >= 0 && i < n && j >= 0 && j < m;
}
int bfs(int ki, int kj, int qi, int qj)
{
    if( ki==qi && kj==qj)
     {
        return 0;
     }

    memset(vis,false,sizeof(vis));

    queue<pair<int, int>> q;

    q.push({ki, kj});
    vis[ki][kj] = true;

    int count=0;

    while (!q.empty())
    {
        int size = q.size();
        count++;
        for(int i=0;i<size;i++)
        {

        pair<int, int> par = q.front();
        int a = par.first, b = par.second;
        q.pop();
        for (const auto& move : d)
        {
            int ci = a + move.first;
            int cj = b + move.second;


            if (valid(ci, cj))
            {
                if(ci==qi && cj==qj)
                {
                return count;
                }

                if(!vis[ci][cj])
                {

                vis[ci][cj] = true;
                q.push({ci, cj});

                }
            }

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