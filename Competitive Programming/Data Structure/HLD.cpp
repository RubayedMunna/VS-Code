#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define N '\n'
#define Fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

const ll maxn = 1e5 + 10;
vector<ll> adj[maxn + 2];
ll siz[maxn + 2], ent[maxn + 2], tim, head[maxn + 2], par[maxn + 2], lev[maxn + 2];

void dfs(ll n,ll p,ll l)
{
    siz[n] = 1, par[n] = p, lev[n] = l;

    for(auto x:adj[n])
    {
        if(x==p)
        {
            continue;
        }
        dfs(x, n, l + 1);
        siz[n] += siz[x];
    }
}

void hld(ll n,ll p)
{
    ent[n] = ++tim;
    ll mx = -1, b = -1;

    for(auto x:adj[n])
    {
        if(x==p)
        {
            continue;
        }
        if(siz[x]>mx)
        {
            mx = siz[x];
            b = x;
        }
    }

    if(b!=-1)
    {
        head[b] = head[n];
        hld(b, n);
    }

    for(auto x:adj[n])
    {
        if(x==p||x==b)
        {
            continue;
        }
        head[x] = x;
        hld(x, n);
    }
}

ll hQry(ll u,ll v)
{
    if(lev[v]<lev[u])
    {
        swap(u, v);
    }

    if(head[u]==head[v])
    {
        // return qry(ent[v],ent[u]);
        
    }

    if(lev[head[u]]<lev[head[v]])
    {
        swap(u, v);
    }
    // qry(ent[head[u]],ent[u])

    u = par[head[u]];
}

void solve(ll tst)
{
    ll n;
    cin >> n;
    ll m;
    cin >> m;
    
}
int main()
{
    ll t=1;
    //cin>>t;
    ll tst=0;
    while(t--)
    {
        solve(++tst);
    }
    return 0;
}