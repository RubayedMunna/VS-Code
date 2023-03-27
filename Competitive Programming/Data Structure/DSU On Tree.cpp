

/* 
Codeforces Problem 600 E Lomsat gelral (related to DSU on Tree) 
*/


#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define N '\n'
#define Fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

const ll Size=1e5+9;
vector<ll>adj[Size];
ll color[Size];
ll sz[Size];
ll freq[Size];
ll freq_of_freq[Size];
ll sum_of_freq[Size];
bool big[Size];
ll val[Size];
ll dom=0;
ll n;


void size_dfs(ll node,ll par)
{
    sz[node]=1;
    for(auto it:adj[node])
    {
        if(it!=par)
        {
            size_dfs(it,node);
            sz[node]+=sz[it];
        }
    }
}

void add(ll node,ll par)
{
    if(freq[color[node]])
    {
        sum_of_freq[freq[color[node]]]-=color[node];
    }
    if(freq[color[node]])
    {
        if(freq_of_freq[freq[color[node]]])freq_of_freq[freq[color[node]]]--;
    }

    freq[color[node]]++;
    freq_of_freq[freq[color[node]]]++;
    if(freq[color[node]]>dom)
    {
        dom=freq[color[node]];
    }

    sum_of_freq[freq[color[node]]]+=color[node];

    for(auto it:adj[node])
    {
        if(it!=par&&!big[it])
        {
            add(it,node);
        }
    }
}

void rem(ll node,ll par)
{
    if(freq[color[node]])
    {
        sum_of_freq[freq[color[node]]]-=color[node];
    }
    if(freq[color[node]])
    {
        if(freq_of_freq[freq[color[node]]])freq_of_freq[freq[color[node]]]--;
    }
    if(dom==freq[color[node]])
    {
        if(freq_of_freq[freq[color[node]]]==0)
        {
            dom--;
        }
    }
    freq[color[node]]--;

    if(freq[color[node]])
    {
        freq_of_freq[freq[color[node]]]++;
    }
    if(freq[color[node]])
    {
        sum_of_freq[freq[color[node]]]+=color[node];
    }

    for(auto it:adj[node])
    {
        if(it!=par&&!big[it])
        {
            rem(it,node);
        }
    }
}

void dfs(ll node,ll par,ll keep)
{
    ll siz=-1,bigchild=-1;

    for(auto it:adj[node])
    {
        if(it!=par)
        {
            if(sz[it]>siz)
            {
                siz=sz[it];
                bigchild=it;
            }
        }
    }

    for(auto it:adj[node])
    {
        if(it!=par&&it!=bigchild)
        {
            dfs(it,node,0);
        }
    }

    if(bigchild!=-1)
    {
        dfs(bigchild,node,1);
        big[bigchild]=1;
    }

    add(node,par);

    val[node]=sum_of_freq[dom];

    if(bigchild!=-1)
    {
        big[bigchild]=0;
    }

    if(keep==0)
    {
        rem(node,par);
    }
}

int main()
{
    cin>>n;
    for(ll i=1;i<=n;i++)
    {
        cin>>color[i];
    }

    for(ll i=1;i<n;i++)
    {
        ll u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    size_dfs(1,1);
    dfs(1,1,1);
    for(ll i=1;i<=n;i++)
    {
        cout<<val[i]<<" ";
    }
    cout<<N;
    return 0;
}