#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define N '\n'
#define Fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

const ll mod = 1000001011, b = 193;
const ll maxn=1e5+10;
ll pw[maxn + 2];
void cal(ll n)
{
    pw[0] = 1;

    for (ll i = 1;i<=n;i++)
    {
        pw[i] = (1LL * pw[i - 1] * b) % mod;
    }
}

ll h[maxn + 2];
string s;

void makeHash()
{
    ll hs = 0, i = 0;
    for(auto x:s)
    {
        hs = (1LL * hs * b + x) % mod;
        h[i++] = hs;
    }
}

ll get(ll i,ll j)
{
    ll x = h[j];
    if(!i)
    {
        return x;
    }
    x = x - (1LL * h[i - 1] * pw[j - i + 1]) % mod;
    if(x<0)
    {
        x += mod;
    }
    return x;
}

ll sz;

bool cmp(ll a,ll b)
{
    ll mx = sz - max(a, b);
    ll left = 0, right = mx, md;

    while(left<=right)
    {
        ll mid = (left + right) / 2;
        if(get(a,a+mid)==get(b,b+mid))
        {
            left = mid + 1;
        }
        else 
        {
            right = mid - 1;
        }
    }
    if((a+left)==sz)
    {
        return true;
    }
    if(b+left==sz)
    {
        return false;
    }
    return s[a + left] < s[b + left];
}

vector<ll>suffixSort()
{
    sz = s.size();
    cal(sz);
    makeHash();
    vector<ll> v;
    for (ll i = 0; i < sz;i++)
    {
        v.push_back(i);
    }
    sort(v.begin(), v.end(), cmp);
    return v;
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