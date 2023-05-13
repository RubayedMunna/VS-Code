

#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
//using u64 = uint64_t;
//using u128 = __uint128_t;
#define ll long long
#define N '\n'
#define Fast ios_base::sync_with_stdio(false); cin.tie(NULL)
#define File freopen("in.txt","r",stdin)

struct LCA
{
    vector<ll>height,euler,first,segtree;
    vector<ll>visited;
    vector<vector<ll>>adj;

    ll n;

    LCA(vector<vector<ll>>&add,ll root)
    {

        adj=add;
        n=adj.size();
        height.resize(n);
        first.resize(n);
        euler.reserve(2*n);
        visited.assign(n,false);

        DFS(root);

        ll m=euler.size();
        segtree.resize(4*m);

        build(1,0,m-1);

    }

    void DFS(ll node,ll h=0)
    {
        visited[node]=true;
        height[node]=h;
        first[node]=euler.size();
        euler.push_back(node);

        for(auto v:adj[node])
        {
            if(!visited[v])
            {
                DFS(v,h+1);
                euler.push_back(node);
            }
        }
    }

    void build(ll node,ll st,ll en)
    {
        if(st==en)
        {
            segtree[node]=euler[st];
            return;
        }

        ll mid=(st+en)>>1;

        build(node<<1,st,mid);
        build(node<<1|1,mid+1,en);

        ll l=segtree[node<<1],r=segtree[node<<1|1];

        segtree[node]=height[l]<height[r]? l:r;
    }

    ll query(ll node,ll st,ll en,ll l,ll r)
    {
        if(st>r||en<l)
        {
            return -1;
        }
        if(st>=l&&en<=r)
        {
            return segtree[node];
        }

        ll mid=(st+en)>>1;

        ll left=query(node<<1,st,mid,l,r);
        ll right=query(node<<1|1,mid+1,en,l,r);

        if(left==-1) return right;
        if(right==-1) return left;

        return height[left]<height[right]? left:right;
    }


    ll lca(ll u,ll v)
    {
        ll left=first[u];
        ll right=first[v];

        if(left>right)swap(left,right);

        return query(1,0,euler.size()-1,left,right);
    }
};

void solve(ll tst)
{
    cout<<"Case "<<tst<<":"<<N;
    ll n;
    cin>>n;

    vector<vector<ll>>adj(n+1);

    for(ll i=1;i<=n;i++)
    {
        ll xx;
        cin>>xx;
        for(ll j=1;j<=xx;j++)
        {
            ll yy; cin>>yy;
            adj[i].push_back(yy);
            adj[yy].push_back(i);
        }

    }
    LCA lc(adj,1);

    ll q;
    cin>>q;
    while(q--)
    {
        ll u,v;
        cin>>u>>v;
        cout<<lc.lca(u,v)<<N;
    }

}

int main()
{
    Fast;
    ll t=1;
    cin>>t;
    ll tst=0;
    while(t--)
    {
        solve(++tst);
    }
}
