#include <bits/stdc++.h>
using namespace std;

const long long int INF = 1e18+5;
vector<long long int> dis;

class Edge
{
public:
    int a, b, w;
    Edge(int a, int b, int w)
    {
        this->a = a;
        this->b = b;
        this->w = w;
    }
};
int main()
{
    int n, e;
    cin >> n >> e;
    vector<Edge> EdgeList;
    while(e--){
        int a,b,w;
        cin>>a>>b>>w;
        EdgeList.push_back(Edge(a, b, w));
    }

    int s;
    cin>>s;
    dis.resize(n+1,INF);
    dis[s]=0;

    for (int i = 1; i <= n - 1; i++)
    {
        for (Edge ed : EdgeList)
        {
            int a, b, w;
            a = ed.a;
            b = ed.b;
            w = ed.w;
            if (dis[a] < INF && dis[a] + w < dis[b])
            {
                dis[b] = dis[a] + w;
            }
        }
    }

    bool neg_cycle=false;
    for(const Edge& ed : EdgeList)
    {
        if(dis[ed.a] < INF && dis[ed.a]+ ed.w < dis[ed.b])
        {
            neg_cycle = true;
            break;
        }
    }
    if(neg_cycle)
    {
        cout<<"Negative Cycle Detected"<<endl;
        return 0;
    }

    int t;
    cin>>t;
    while(t--)
    {
        int d;
        cin>>d;
        if(dis[d]==INF)
        {
            cout<<"Not Possible"<<endl;
        }
        else{
            cout<<dis[d]<<endl;
        }
    }
    return 0;
}