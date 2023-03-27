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
    ll n;
    cin>>n;

    ll a[n+10],b[n+10],c[n+10],d[n+10];

    for(ll i=1;i<=n;i++)
    {
        cin>>a[i]>>b[i];
        c[i]=a[i]*b[i];
    }


    ll cnt=0;


    ll gcd,lcm;

    for(ll i=1;i<=n;i++)
    {
        if(i==1)
        {
            cnt++;
            gcd=c[i];
            lcm=b[i];
            continue;
        }

        gcd=__gcd(gcd,c[i]);
        lcm=(lcm*b[i])/__gcd(lcm,b[i]);

        if(gcd%lcm!=0)
        {
            cnt++;
            gcd=c[i];
            lcm=b[i];
        }
    }

    cout<<cnt<<N;


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
