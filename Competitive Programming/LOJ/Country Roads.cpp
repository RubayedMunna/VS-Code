#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define N '\n'
#define Fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);


const ll MAX_ELEMENT=1000;
ll n,m;
ll ara[MAX_ELEMENT];
struct Node
{
    ll  att,cost;
    Node(ll _att,ll _cost)
    {
        att=_att;
        cost=_cost;
    }
};
bool operator<(Node A,Node B)
{
    return A.cost>B.cost;
}
struct Edge
{
    ll v;
    ll w;
};
vector<Edge>adj[MAX_ELEMENT];


ll dist[MAX_ELEMENT];

void Dijkstra(ll s)
{
    priority_queue<Node>PQ;
    for(ll i=0;i<n;i++)
    {
        dist[i]=LLONG_MAX;
    }
    dist[s]=0;
    PQ.push(Node(s,0));
    while(!PQ.empty())
    {
        Node u=PQ.top();
        PQ.pop();
        if(u.cost!=dist[u.att])
        {
            continue;
        }
        for(Edge e:adj[u.att])
        {
            if(dist[e.v]>max(u.cost,e.w))
            {
                dist[e.v]=max(u.cost,e.w);
                PQ.push(Node(e.v,dist[e.v]));
            }
        }
    }

    for(ll i=0;i<n;i++)
    {
        if(dist[i]==LLONG_MAX)
        {
            cout<<"Impossible"<<N;
        }
        else
        {
            cout<<dist[i]<<N;
        }
    }
}


void solve(ll tst)
{
    cin>>n>>m;
    for(ll i=0;i<=n;i++)
    {
        adj[i].clear();

    }

    for(ll i=1;i<=m;i++)
    {
        ll u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }

    ll source;
    cin>>source;
    cout<<"Case "<<tst<<":"<<N;
    Dijkstra(source);

}
int main()
{
    ll t=1;
    cin>>t;
    ll tst=0;
    while(t--)
    {
        solve(++tst);
    }
    return 0;
}
