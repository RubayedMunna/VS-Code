#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define N '\n'
#define Fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
void solve(ll tst)
{
    ll n;
    char d;
    cin>>n>>d;
    string str;
    cin >> str;

    ll len = str.size();
    ll pos = len;

    for (ll i = 0; i < len;i++)
    {
        if(str[i]>=d)
        {
            continue;
        }
        else 
        {
            pos = i;
            break;
        }
    }

    string ans = "";

    if(pos>0)
    {
        for (ll i = 0; i < pos;i++)
        {
            ans += str[i];
        }
    }
    ans += d;
    if(pos<len)
    {
        for (ll i = pos; i < len;i++)
        {
            ans+=str[i];
        }
    }
    cout << ans << N;
}
int main()
{
    ll t = 1;
    cin >> t;
    ll tst = 0;
    while (t--)
    {
        solve(++tst);
    }
    return 0;
}