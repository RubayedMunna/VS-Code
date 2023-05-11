#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define N '\n'
#define Fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

const ll maxn = 1e5 + 10;

ll aa[maxn + 2];
ll sp[maxn + 2][20 + 2];

void build(ll n)
{
    for (ll i = 1;i<=n;i++)
    {
        sp[i][0] = aa[i];
    }
    for (ll j = 1; j <= 20;j++)
    {
        for (ll i = 1;i<=n;i++)
        {
            sp[i][j] = sp[i][j - 1];
            if ((i + (1 << (j - 1))) <= n)
            {
                sp[i][j] = min(sp[i][j - 1], sp[i + (1 << (j - 1))][j - 1]);

            }
        }
    }
}

ll get(ll lt,ll rt)
{
    ll dg = 31 - __builtin_clz(rt - lt + 1);
    return min(sp[lt][dg], sp[rt - (1 << dg) + 1][dg]);
}

int main()
{
    ll n;
    cout << "Enter Number of Elements: " << N;

    cin >> n;
    cout << "Enter Elements: " << N;
    for (ll i = 1; i <= n; i++)
    {
        cin >> aa[i];
    }

    build(n);
    cout<<"Number of Queries: "<<N;
    ll query;
    cin >> query;
    while(query--)
    {
        ll l, r;
        cin>>l>>r;
        cout << get(l, r) << N;
    }
}