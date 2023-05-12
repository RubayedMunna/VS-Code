#include <bits/stdc++.h>
using namespace std;
#define N '\n'
#define ll long long
#define Fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);


const ll maxn = 1e4;
ll arr[maxn];
ll lazy[maxn];
ll block[maxn];
ll rn;
ll Query(ll l,ll r)
{
    ll mn=LLONG_MAX;
    ll lb=(l-1)/rn+1;
    ll rb=(r-1)/rn+1;
    for(ll i=lb+1; i<=rb-1; i++)
    {
        if(lazy[i])
        {
            mn=min(mn,lazy[i]);
        }
        else
        {
            mn=min(mn,block[i]);
        }
    }
    if(lazy[lb])
    {
        for(ll i=rn*(lb-1)+1; i<=rn*lb; i++)
        {
            arr[i]=lazy[lb];
        }
        lazy[lb]=0;
        block[lb]=LLONG_MAX;
        for(ll i=rn*(lb-1)+1; i<=rn*lb; i++)
        {
            block[lb]=min(block[lb],arr[i]);
        }
    }
    for(ll i=l; i<=min(r,lb*rn); i++)
    {
        mn=min(mn,arr[i]);
    }

    if(lb<=rn)
    {
        if(lazy[rb])
        {
            for(ll i=rn*(rb-1)+1; i<=rn*rb; i++)
            {
                arr[i]=lazy[lb];
            }
            lazy[rb]=0;
            block[rb]=LLONG_MAX;
            for(ll i=rn*(rb-1)+1; i<=rn*rb; i++)
            {
                block[rb]=min(block[rb],arr[i]);
            }
        }
        for(ll i=max(l,rn*(rb-1)+1); i<=r; i++)
        {
            mn=min(mn,arr[i]);
        }
    }
    else
    {
        for(ll i=rn*(rb-1)+1; i<=r; i++)
        {
            mn=min(mn,arr[i]);
        }
    }



    return mn;
}
ll update(ll l,ll r,ll value)
{
    ll lb=(l-1)/rn+1;
    ll rb=(r-1)/rn+1;
    for(ll i=lb+1; i<=rb-1; i++)
    {
        lazy[i]=value;
    }
    if(lazy[lb])
    {
        for(ll i=rn*(lb-1)+1; i<=rn*lb; i++)
        {
            arr[i]=lazy[lb];
        }
        lazy[lb]=0;

    }
    for(ll i=l; i<=min(r,lb*rn); i++)
    {
        arr[i]=value;
    }
    block[lb]=LLONG_MAX;
    for(ll i=(lb-1)*rn+1; i<=lb*rn; i++)
    {
        block[i]=min(block[i],arr[i]);
    }
    if(rb<=rn)
    {
        if(lazy[rb])
        {
            for(ll i=rn*(rb-1)+1; i<=rn*rb; i++)
            {
                arr[i]=lazy[rb];
            }
            lazy[rb]=0;

        }
        for(ll i=max(l,rn*(rb-1)+1); i<=r; i++)
        {
            arr[i]=value;

        }
        block[rb]=LLONG_MAX;
        for(ll i=(rb-1)*rn+1; i<=rb*rn; i++)
        {
            block[i]=min(block[i],arr[i]);
        }
    }
    else
    {
        for(ll i=rn*(rb-1)+1; i<=r; i++)
        {
            arr[i]=value;
        }
    }

}
int main()
{
    ll n;
    cout<<"Enter Number of Elements: ";
    cin>>n;
    cout << "Enter Elements: ";
    
    for (ll i = 1; i <= n; i++)
    {
        cin>>arr[i];
    }
    rn=sqrt(n);
    ll block_size=n/rn;
    for(ll i=1; i<=block_size; i++)
    {
        ll mn=LLONG_MAX;

        for(ll j=(i-1)*rn+1; j<=i*rn; j++)
        {
            if(arr[j]<mn)
            {
                mn=arr[i];
                block[i]=mn;

            }
        }
    }
    
    cout << "Enter Number of Query: ";
    ll query;
    cin >> query;
    cout << "Enter 1 for Range Minimum Query"<<N;
    cout << "Enter 2 for Range Update" << N;
    while (query--)
    {
        ll type;
        cin>>type;
        if(type==1)
        {
            ll l,r;
            cin>>l>>r;
            ll t=(l-1)/rn+1;

            if(t>rn)
            {
                ll mn=LLONG_MAX;
                for(ll i=l; i<=r; i++)
                {
                    mn=min(mn,arr[i]);
                }

            }
            else
            {
                cout<<Query(l,r)<<N;
            }

        }
        else if(type==2)
        {
            ll l,r,value;
            cin>>l>>r>>value;
            ll t=(l-1)/rn+1;
            if(t>rn)
            {
                for(ll i=l; i<=r; i++)
                {
                    arr[i]=value;
                }

            }
            else
            {
                cout<<6<<N;
                update(l,r,value);
            }


        }
    }
}