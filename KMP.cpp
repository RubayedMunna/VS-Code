#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define N '\n'
#define Fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

vector<ll>pi;

void prefix_function(string str)
{
    ll n=(ll)str.length();

    pi.assign(n,0);

    for(ll i=1;i<n;i++)
    {
        ll j=pi[i-1];

        while(j>0&&str[i]!=str[j])
        {
            j=pi[j-1];
        }

        if(str[i]==str[j])
        {
            j++;
        }
        pi[i]=j;
    }
}

void solve(ll tst)
{
    string s,t;
    cin>>t>>s;

    ll n=s.size();
    ll m=t.size();

    string str=s+"$"+t;

    prefix_function(str);

    for(ll i=0;i<pi.size();i++)
    {
        cout<<pi[i]<<" ";
    }
    cout<<N;
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