#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define N '\n'
#define Fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
void solve(ll tst)
{
    ll n;
    cin>>n;
    string str;
    cin>>str; str=" "+str;

    ll idx=1;
    char mn=str[1];

    for(ll i=1;i<=n;i++)
    {
        if(str[i]<=mn)
        {
            mn=str[i];
            idx=i;
        }
    }
    string ans="";
    ans+=mn;

    if(idx>1)
    {
        for(ll i=1;i<idx;i++)
        {
            ans+=str[i];
        }
    }

    if(idx<n)
    {
        for(ll i=idx+1;i<=n;i++)
        {
            ans+=str[i];
        }
    }
    cout<<ans<<N;
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