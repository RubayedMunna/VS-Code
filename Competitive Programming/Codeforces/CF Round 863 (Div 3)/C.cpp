#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define N '\n'
#define Fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

void solve(ll tst)
{
    ll n;
    cin >> n;
    ll b[n + 10];
    vector<ll> a;
    for (ll i = 1; i < n;i++)
    {
        cin >> b[i];
    }
    a.push_back(b[1]);

    for (ll i = 1; i < n;i++)
    {
        a.push_back(min(b[i], b[i + 1]));
    }
    //a.push_back(b[n - 1]);

    for(auto it:a)
    {
        cout << it << " ";
    }
    cout << N;
}
int main()
{
    Fast;
    ll t = 1;
    cin >> t;
    ll tst = 0;
    while(t--)
    {
        solve(++tst);
    }
    return 0;
}