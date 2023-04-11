#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define N '\n'
#define Fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

vector<ll>RabinKarp(string const& s,string const& t)
{
    const ll p = 37;
    const ll m = 1e9 + 7;

    ll ls = (ll)s.size();
    ll lt = (ll)t.size();

    vector<ll> p_pow(max(ls, lt));

    p_pow[0] = 1;

    for (ll i = 1; i < p_pow.size();i++)
    {
        p_pow[i] = (p_pow[i - 1] * p) % m;
    }

    vector<ll> h(lt + 1, 0);

    for (ll i = 0;i<lt;i++)
    {
        h[i + 1] = (h[i] + (t[i] - 'a' + 1) * pow[i]) % m;
    }

    vector<ll> occurences;

    for (ll i = 0; i + ls - 1 < T;i++)
    {
        ll cur_h = (h[i + ls] + m - h[i]) % m;
        if(cur_h==h_s*p_pow[i]%m)
        {
            occurences.emplace_back(i);
        }
    }
    return occurences;
}

void solve(ll tst)
{

}

int main()
{
    ll t = 1;
    cin >> t;
    ll tst = 0;
    while(t--)
    {
        solve(++tst);
    }
}