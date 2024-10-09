#include<bits/stdc++.h>
using namespace std;

char graph[1001][1001];
bool vis[1001][1001];

int n,m;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

bool isValid(int x,int y)
{
    if (x >= 0 && x < n && y >= 0 && y < m && graph[x][y] == '.' && !vis[x][y])
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool bfs(int si, int sj, int di, int dj)
{

    queue<pair<int, int>> q;
    q.push({si, sj});
    vis[si][sj] = true;

    while (!q.empty())
    {

        pair<int, int> node = q.front();
        q.pop();
        int nrow = node.first;
        int ncol = node.second;

        if(nrow==di && ncol==dj)
        {
            return true;
        }

        for (int i = 0; i < 4; i++)
        {

            int ci = nrow + dx[i];
            int cj = ncol + dy[i]; 

            if (isValid(ci, cj))
            {
                vis[ci][cj] = true;
                q.push({ci, cj});
            }
        }
    }
    return false;
}

int main()
{

    cin>>n>>m;

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>graph[i][j];
        }
    }

    int si,sj,di,dj;
    cin>>si>>sj>>di>>dj;
    
    if(graph[si][sj]=='-' || graph[di][dj]=='-')
    {
        cout<<"NO"<<endl;
        return 0;
    }
       
    if(bfs(si,sj,di,dj))
    {
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }
    return 0;
}