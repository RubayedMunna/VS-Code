#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define N '\n'
#define Fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
void solve(ll tst)
{
    ll n,c,d;
    cin>>n>>c>>d;
    map<ll,ll>mp;

    for(ll i=1;i<=n;i++)
    {
        ll x;
        cin>>x;
        mp[x]++;
    }

    ll nichi=0,baad=0,nitehobe=0;
    ll ans=LLONG_MAX;



    for(auto it:mp)
    {
        ll xx=it.first;
        nichi++;
        nitehobe=xx-nichi;

        if(mp[xx]>1)
        {
            baad+=mp[xx]-1;
        }

        ll baadd=max(0LL,n-(nichi+baad));

        //ll baadd=baad+(n-nichi);

        

        ans=min(ans,(baadd*c+nitehobe*d));

    }

    cout<<ans<<N;
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
    return 0;
}