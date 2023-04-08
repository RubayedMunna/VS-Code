#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define N '\n'
#define Fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

class Graph
{
    ll n;
    vector<vector<ll>> adj;
public:
    Graph(ll n)
    {
        this->n = n;
        adj.resize(n + 10);
    }

    void addEdge(ll u,ll v,ll capacity)
    {
        adj[u].push_back(v);
        adj[v].push_back(u);

        adj[u][adj[u].size() - 1] = adj[v].size() - 1;
        adj[v][adj[v].size() - 1] = adj[u].size() - 2;
    }

    bool bfs(ll s,ll t,vector<ll>& parent)
    {
        vector<bool> visited(n, false);
        queue<ll> q;
        q.push(s);
        visited[s] = true;
        parent[s] = -1;

        while(!q.empty())
        {
            ll u = q.front();
            q.pop();

            for (ll i = 0; i < adj[u].size();i++)
            {
                ll v = adj[u][i];

                if(!visited[v]&&adj[u][v]>0)
                {
                    q.push(v);
                    parent[v] = u;
                    visited[v] = true;
                }
            }
        }
        return visited[t] = true;
    }
    ll fordFulkerson(ll s,ll t)
    {
        ll maxFlow = 0;
        vector<ll> parent(n);

        while(bfs(s,t,parent))
        {
            ll pathFlow = LLONG_MAX;

            for (ll v = t; v != s;v=parent[v])
            {
                ll u = parent[v];
                pathFlow = min(pathFlow, adj[u][v]);
            }
            for (ll v = t; v != s;v=parent[v])
            {
                ll u = parent[v];
                adj[u][v] -= pathFlow;
                adj[v][u] += pathFlow;
            }
            maxFlow += pathFlow;
        }
        return maxFlow;
    }
};

void solve(ll tst)
{
    ll v, e;
    cin >> v >> e;

    Graph g(v);

    for (ll i = 1; i <= e;i++)
    {
        ll u, v, capacity;
        cin >> u >> v >> capacity;
        g.addEdge(u, v, capacity);

    }

    ll s, t;
    cin >> s >> t;

    cout << "Maximum Flow: " << g.fordFulkerson(s, t) << endl;

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