#include<bits/stdc++.h> 
using namespace std;

const long long int INF = 1e18;
int n,e;

vector<pair<int,int>> adj[100005];
long long int dis[100005];

void dijkstra(int src,int n){

    for(int i=1;i<=n;i++){
        dis[i] = INF;
    }

    dis[src] = 0;
    priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>>pq;
    pq.push({dis[src],src});

    while(!pq.empty()){
        pair<int,int> parent = pq.top();
        pq.pop();


        int parentNode = parent.second;
        int parentCost = parent.first;

        if(parentCost > dis[parentNode])
        {
            continue;
        }

        for(auto child:adj[parentNode]){
            int childCost = child.first;
            int childNode = child.second;

            if(dis[parentNode]+childCost<dis[childNode]){
                dis[childNode] = dis[parentNode]+childCost;
                pq.push({dis[childNode],childNode});

            }
        }
    }
}

int main(){
    cin>>n>>e;

    while(e--){
        int a,b;
        long long w;
        cin>>a>>b>>w;

        adj[a].push_back(make_pair(w,b));
    }

    int src;
    cin>>src;

    dijkstra(src,n);

    int t;
    cin>>t;
    while(t--)
    {
        int d;
        long long dw;
        cin>>d>>dw;

        if(dis[d]<=dw)
        {
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }

    return 0;
}