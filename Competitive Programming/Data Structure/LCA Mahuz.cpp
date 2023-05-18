#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define mkp make_pair
#define mkt make_tuple
#define lb lower_bound
#define ub upper_bound
#define N "\n"
#define pb push_back
#define pob pop_back
#define ff first
#define ss second
#define bb begin()
#define rbb rbegin()
#define ee end()
#define ree rend()
#define pi acos(-1)
#define inf LLONG_MAX

const ll mx=1000005,lev=18;
using namespace std;
vector <ll> tree[mx];
ll par[mx][lev],depth[mx],n,m;
void dfs(ll node, ll prev)
{
    depth[node]= ++depth[prev];
    par[node][0]=prev;
    for(ll i=0;i<tree[node].size();i++)
    {
        if(tree[node][i]!=prev) dfs(tree[node][i],node);
    }
}
void sparseTable()
{
    ll i,node;
    for(i=1;i<lev;i++)
    {
        for(node=1;node<=n;node++)
        {
            if(par[node][i-1]!=-1)
                par[node][i]=par[par[node][i-1]][i-1];
        }
    }
}
ll lca(ll u, ll v)
{
    if(depth[v]<depth[u]) swap(u,v);
    ll dif=depth[v]-depth[u];
    for(ll i=0;i<lev;i++)
    {
        if((dif >> i) & 1) v=par[v][i];
    }

    if(u==v) return u;

    for(ll i=lev-1;i>=0;i--)
    {
        if(par[u][i]!=par[v][i])
        {
            u=par[u][i];
            v=par[v][i];
        }
    }
    return par[u][0];
}
int main()
{
    ll q; memset(par,-1,sizeof(par));
    cout<<"Lowest Common Ancestor of 2 nodes in a tree"<<N<<N;
    cout<<"Enter the number of nodes: "; cin>>n; m=n-1;
    cout<<"Enter the edges:"<<N;
    while(m--)
    {
        ll u,v; cin>>u>>v;
        tree[u].pb(v);
        tree[v].pb(u);
    }
    depth[0]=0;
    dfs(1,0); // Pre-calculate depth of each node
    sparseTable(); // Pre-calculate the 2^i th ancestor for each node
    cout<<"Enter the number of queries: "; cin>>q;
    while(q--)
    {
        ll a,b; cin>>a>>b;
        cout<<"LCA("<<a<<", "<<b<<") = "<<lca(a,b)<<N;
    }
    return 0;
}
