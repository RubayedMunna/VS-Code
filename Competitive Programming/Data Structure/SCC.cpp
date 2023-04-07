#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define N '\n'
#define Fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);


struct SCC{

    const static ll maxn = 2000 + 7;

    vector<ll> adj[maxn], r_adj[maxn];

    ll V, visit[maxn], color[maxn],cnt;

    stack<ll> stk;

    SCC(ll V):V(V),cnt(0)
    {
        memset(visit, 0, sizeof(visit));
    }

    void add_edge(ll x,ll y)
    {
        adj[x].push_back(y);
        r_adj[y].push_back(x);
    }

    void dfs(ll u)
    {
        visit[u] = true;

        for(ll v:adj[u])
        {
            if(!visit[v])
            {
                dfs(v);
            }
        }
        stk.push(u);
    }

    void dfs(ll u,ll id)
    {
        visit[u] = false;
        color[u] = id;

        for(ll v:r_adj[u])
        {
            if(visit[v])
            {
                dfs(v, id);
            }
        }
    }

    ll get()
    {
        for (ll i = 1; i <= V;i++)
        {
            if(!visit[i])
            {
                dfs(i);
            }
        }

        while(stk.size())
        {
            ll v = stk.top();
            stk.pop();
            if(visit[v])
            {
                dfs(v, ++cnt);
            }
        }
        return cnt;
    }
};

int main()
{
    
}