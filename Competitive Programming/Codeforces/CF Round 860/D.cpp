#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
//using u64 = uint64_t;
//using u128 = __uint128_t;
#define ll long long
#define N '\n'
#define Fast ios_base::sync_with_stdio(false); cin.tie(NULL)
#define File freopen("in.txt","r",stdin)

const ll maxn=5e4+10;

vector<ll>v[maxn];

void solve(ll tst)
{
    ll n;
    cin>>n;
    ll arr[n+10];
    stack<ll>pos,neg,zero;
    bool flg=false;
    for(ll i=1;i<=n;i++)
    {
        cin>>arr[i];
        if(arr[i])flg=true;

        if(arr[i]>0)
        {
            pos.push(arr[i]);
        }
        else if(arr[i]<0)
        {
            neg.push(arr[i]);
        }
        else 
        {
            zero.push(arr[i]);
        }
    }

    if(flg==false)
    {
        cout<<"No"<<N;
        return;
    }

    // cout<<"Positive Stack: "<<N;

    // while(!pos.empty())
    // {
    //     cout<<pos.top()<<" ";
    //     pos.pop();
    // }
    // cout<<N;

    // cout<<"Negative Stack: "<<N;

    // while(!neg.empty())
    // {
    //     cout<<neg.top()<<" ";
    //     neg.pop();
    // }
    // cout<<N;

    // cout<<zero.empty()<<N;

    vector<ll>ans;

    ll sum=0;

    ll x=n;

    while(!zero.empty())
    {
        ans.push_back(zero.top());
        zero.pop();
        x--;
    }
    //cout<<"x = "<<x<<N;


    while(x--)
    {
        if(sum<=0)
        {
            ans.push_back(pos.top());
            sum+=pos.top();
            pos.pop();
            
        }
        else 
        {
            ans.push_back(neg.top());
            sum+=neg.top();
            neg.pop();
            
        }
    }

    cout<<"Yes"<<N;

    for(auto it:ans)
    {
        cout<<it<<" ";
    }
    cout<<N;
}

int main()
{
    Fast;
    //File;
    ll t=1;
    cin>>t;
    ll tst=0;
    while(t--)
    {
        solve(++tst);
    }
    return 0;
}
