#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define N '\n'
#define Fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);



class DFS{
public:
    vector<vector<ll>> adj;
    vector<bool> visited;
public:
    DFS(ll n)
    {
        adj.resize(n + 10);
        visited.resize(n + 10, false);
    }

    void addEdge(ll u,ll v)
    {
        adj[u].push_back(v);
        adj[v].push_back(u); //only when graph is undirected
    }

    void dfs(ll node)
    {
        visited[node] = true;
        cout << node << " ";
        for(ll v:adj[node])
        {
            if(!visited[v])
            {
                dfs(v);
            }
        }
    }
};

void solve(ll tst)
{
    ll n;
    cin >> n;

    DFS G(n);

    ll m;
    cin >> m;

    for (ll i = 1; i <= m;i++)
    {
        ll u, v;
        cin >> u >> v;
        G.addEdge(u, v);
    }

    for (ll i = 1; i <= n;i++)
    {
        if(!G.visited[i])
        {
            G.dfs(i);
            cout << N;
        }
    }
}
int main()
{
    ll t = 1;
    cin >> t;
    ll tst = 0;
    while(t--)
    {
        solve(++tst);
    }
    return 0;
}