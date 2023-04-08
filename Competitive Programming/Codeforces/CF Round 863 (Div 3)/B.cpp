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
    ll n, x1, x2, y1, y2;
    cin >> n >> x1 >> y1 >> x2 >> y2;

    if(x1>(n/2))
    {
        x1 = n - x1 + 1;
    }
    if(y1>(n/2))
    {
        y1 = n - y1 + 1;
    }
    if(x2>(n/2))
    {
        x2 = n - x2 + 1;
    }
    if(y2>(n/2))
    {
        y2 = n - y2 + 1;
    }

    ll xx1 = min(x1, y1);
    ll xx2 = min(x2, y2);
    ll ans = fabs(xx1 - xx2);
    cout << ans << N;
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