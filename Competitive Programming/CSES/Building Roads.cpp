#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define N '\n'
#define Fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);


const ll maxn=2e5+9;

vector<ll> adj[maxn];
ll visited[maxn];
ll n, m;

void DFS(ll u)
{
    visited[u] = 1;
    for(ll v:adj[u])
    {
        if(visited[v]==0)
        {
            DFS(v);
        }
    }
}

void solve(ll tst)
{
    cin>>n>>m;
    for (ll i = 1;i<=n;i++)
    {
        adj[i].clear();
        visited[i] = 0;
    }

    for (ll i = 1; i <= m;i++)
    {
        ll u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    
}

int main()
{
    ll t = 1;
    //cin >> t;
    ll tst = 0;
    while(t--)
    {
        solve(++tst);
    }
}