#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define N '\n'
#define Fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

const ll maxn = 1e5 + 10;
vector<ll> adj[maxn];
ll visited[maxn];
bool flg = false;

void DFS(ll u)
{
    visited[u] = 1;
    for(ll v:adj[u])
    {
        if(visited[v])
        {
            flg = true;
        }
        else 
        {
            DFS(v);
        }
    }
}

void solve(ll tst)
{
    ll m;
    cin>>m;
    vector<pair<string, string>> vv;
    for (ll i = 1;i<=m;i++)
    {
        string x, y;
        cin >> x >> y;
        vv.push_back({x, y});
    }

    // for(auto it:vv)
    // {
    //     cout << it.first << " " << it.second << N;
    // }

    ll id = 0;
    map<string, ll> mp;
    for (auto it : vv)
    {
        if(mp[it.first]==0)
        {
            mp[it.first]=id;
            id++;
        }
        if(mp[it.second]==0)
        {
            mp[it.second] = id;
            id++;
        }
    }

    // for (auto it = mp.begin(); it != mp.end();it++)
    // {
    //     cout << it->first << " " << it->second << N;
    // }

    for (ll i = 0; i <= id; i++)
    {
        adj[i].clear();
        visited[i] = 0;
    }

    for (auto it:vv)
    {
        adj[mp[it.first]].push_back(mp[it.second]);
        //adj[mp[it.second]].push_back(mp[it.first]);
    }
    // for (ll i = 0; i < id;i++)
    // {
    //     cout << i << ": ";
    //     for (auto it : adj[i])
    //     {
    //         cout << it << " ";
    //     }
    //     cout << N;
    // }
    flg = false;

    DFS(0);
    cout << "Case " << tst <<": ";
    if (flg)
    {
        cout << "No" << N;
    }
    else 
    {
        cout << "Yes" << N;
    }
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

