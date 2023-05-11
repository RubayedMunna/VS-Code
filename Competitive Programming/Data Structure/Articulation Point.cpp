#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define N '\n'
#define Fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

class ArticulationPoint
{
private:
    ll n; // number of vertices;
    vector<vector<ll>> adj; //adjacency list
    vector<bool> visited; // whatever a vertex visited or not
    vector<ll> parent;
    vector<ll> disc; // discovery time of each node in DFS tree
    vector<ll> low;  // low value of each node in DFS tree

    vector<ll> ap; //whether a vertext is an articulation point or not
    ll time;

    void dfs(ll u)
    {
        visited[u] = true;
        disc[u] = low[u] = ++time;
        ll children = 0;

        for(ll v:adj[u])
        {
            if(!visited[v])
            {
                children++;
                parent[v] = u;
                dfs(v);
                low[u] = min(low[u], low[v]);

                if(parent[u]==-1&&children>1)
                {
                    ap[u] = true;
                }
                else if(parent[u]!=-1&&low[v]>=disc[u])
                {
                    ap[u] = true;
                }
            }
            else
            {
                low[u] = min(low[u], disc[v]);
            }
        }
    }

public:
    ArticulationPoint(ll n)
    {
        this->n = n;
        adj.resize(n + 10);
        visited.resize(n + 10, false);
        parent.resize(n + 10, -1);
        disc.resize(n + 10, n);
        low.resize(n + 10);
        ap.resize(n + 10, false);
        time = 0;
    }

    void addEdge(ll u,ll v)
    {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<ll>findArticulationPoint()
    {
        for (ll i = 1; i <= n;i++)
        {
            if(!visited[i])
            {
                dfs(i);
            }
        }
        vector<ll> result;

        for (ll i = 1; i <= n;i++)
        {
            if(ap[i])
            {
                result.push_back(i);
            }
        }
        return result;
    }
};

void solve(ll tst)
{
    ll n;
    cout << "Enter The Number of Vertices: ";
    cin >> n;
    ArticulationPoint G(n);

    ll m;
    cout << "Enter The Number of Edges: ";
    cin >> m;
    for (ll i = 1; i <= m;i++)
    {
        ll u, v;
        cin >> u >> v;
        G.addEdge(u, v);
    }

    vector<ll> result;
    //result.resize(n + 10);
    result = G.findArticulationPoint();
    cout << "Articulations are: ";
    for (auto it : result)
    {
        cout << it << " ";
    }
    cout << N;
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
    return 0;
}