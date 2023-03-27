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

void solve(ll tst)
{
    ll n;
    cin>>n;
    ll ans=0;
    ll l=0,r=sqrt(LLONG_MAX);
    while(l<=r)
    {
        ll m=(l+r)/2;

        if((m+1)*(m+1)>=n)
        {
            ans=m;
            r=m-1;
        }
        else 
        {
            l=m+1;
        }
    }
    cout<<ans<<N;
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