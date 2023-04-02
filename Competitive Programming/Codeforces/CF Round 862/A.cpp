#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define N '\n'
#define Fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
void solve(ll tst)
{
    ll n;
    cin>>n;
    ll xorr=0;

    for(ll i=1;i<=n;i++)
    {
        ll x;
        cin>>x;
        xorr^=x;
    }
    //cout<<" xor = "<<xorr<<N;
    if(n%2)
    {
        cout<<xorr<<N;
    }
    else 
    {
        if(xorr==0)
        {
            cout<<5<<N;
        }
        else 
        {
            cout<<-1<<N;
        }
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
    return 0;
}