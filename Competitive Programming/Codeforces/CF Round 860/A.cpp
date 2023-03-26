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
    ll arr[n+10],brr[n+10];
    for(ll i=1;i<=n;i++)
    {
        cin>>arr[i];
    }
    for(ll i=1;i<=n;i++)
    {
        cin>>brr[i];
    }

    ll mn=min(arr[n],brr[n]);
    ll mx=max(arr[n],brr[n]);

    bool flg=true;

    for(ll i=1;i<=n;i++)
    {
        if(min(arr[i],brr[i])>mn||max(arr[i],brr[i])>mx)
        {
            flg=false;
            break;
        }
    }
    if(flg)
    {
        cout<<"Yes"<<N;
    }
    else 
    {
        cout<<"No"<<N;
    }
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
