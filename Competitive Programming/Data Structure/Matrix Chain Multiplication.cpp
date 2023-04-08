#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define N '\n'
#define Fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

class MatrixChainMultiplication
{
    public:
        ll matrixChainOrder(vector<ll>p,ll n)
        {
            ll m[n][n];
            for (ll i = 1; i < n;i++)
            {
                m[i][i] = 0;
            }
            for (ll L = 2; L < n;L++)
            {
                for (ll i = 1; i < n - L + 1;i++)
                {
                    ll j = i + L - 1;
                    m[i][j] = LLONG_MAX;
                    for (ll k = i; k < j; k++)
                    {
                        ll q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                        if(q<m[i][j])
                        {
                            m[i][j] = q;
                        }
                    }
                }
            }
            return m[1][n - 1];
        }
};

void solve(ll tst)
{
    MatrixChainMultiplication matrix;

    vector<ll> a = {1, 2, 3, 4, 5};

    cout << "Minimum number of multiplication is " << matrix.matrixChainOrder(a, 5) << N;

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
    return 0;
}