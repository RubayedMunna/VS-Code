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

const ll maxn=5e4+10;

vector<ll>v[maxn];

void solve(ll tst)
{
    ll m;
    cin>>m;

    for(ll i=0;i<=m;i++)
    {
        v[i].clear();
    }

    for(ll i=1;i<=m;i++)
    {
        ll n;
        cin>>n;
        v[i].push_back(n);

        for(ll j=1;j<=n;j++)
        {
            ll x;
            cin>>x;
            v[i].push_back(x);
        }
    }


    // for(ll i=1;i<=m;i++)
    // {
    //     for(ll j=1;j<=v[i][0];j++)
    //     {
    //         cout<<v[i][j]<<" ";
    //     }
    //     cout<<N;
    // }

    // cout<<"&&&"<<N;

    set<ll>st;

    vector<ll>ans;

    bool flg=true;

    for(ll i=m;i>=1;i--)
    {
        bool flgg=false;
        for(ll j=1;j<=v[i][0];j++)
        {
            if(st.find(v[i][j])==st.end())
            {
                if(flgg==false)
                {
                    flgg=true;
                    ans.push_back(v[i][j]);
                }
            }

            st.insert(v[i][j]);
            
        }
        if(flgg==false)
        {
            flg=false;
            break;
        }
        
    }

    if(flg==false )
    {
        cout<<-1<<N;
        return;
    }

    reverse(ans.begin(),ans.end());

    for(auto it:ans)
    {
        cout<<it<<" ";
    }
    cout<<N;

}

int main()
{
    Fast;
    //File;
    ll t=1;
    cin>>t;
    ll tst=0;
    while(t--)
    {
        solve(++tst);
    }
    return 0;
}
