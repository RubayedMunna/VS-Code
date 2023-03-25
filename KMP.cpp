#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define N '\n'
#define Fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

vector<ll> prefix_function(string str)
{
    ll n=(ll)str.length();

    vector<ll>pi(n);

    for(ll i=1;i<n;i++)
    {
        ll j=pi[i-1];

        while(j>0&&str[i]!=str[j])
        {
            j=pi[j-1];
        }

        if(str[i]==str[j])
        {
            pi[i]=j;
        }
    }
    return pi;
}

void solve(ll tst)
{
    string str;
    cin>>str;

    vector<ll>v=prefix_function(str);

    for(ll i=0;i<v.size();i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<N;
}

int main()
{
    ll t=1;
    cin>>t;
    ll tst=0;
    while(t--)
    {
        solve(++tst);
    }
    return 0;
}