#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define N '\n'
#define Fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);


void solve(ll tst)
{
    ll n;
    cin>>n;
    set<ll> st;
    for (ll i = 1;i<=n;i++)
    {
        ll x;
        cin>>x;
        st.insert(x);
    }
    cout << st.size() << N;
}

int main()
{
    ll t=1;
    //cin>>t;
    ll tst=0;
    while(t--)
    {
        solve(++tst);
    }
    return 0;
}
