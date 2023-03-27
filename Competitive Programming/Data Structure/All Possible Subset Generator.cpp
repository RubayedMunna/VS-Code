#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define N '\n'
#define Fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);


/// All Possible Subset Generator Using Bitmasking

ll n;
ll ara[22];
ll ans=0;
void All_Possible_Subset()
{
    for(ll i=0;i<(1<<n);i++)
    {
        for(ll j=0;j<n;j++)
        {
            if(i&(1<<j))
            {
                ///All Possible Subsets Are Ready
                ///Do Whatever You Want to do With All Possible Subset
            }
        }
        
    }
}
int main()
{
    cin>>n;
    for(ll i=0;i<n;i++)
    {
        cin>>ara[i];
    }
    All_Possible_Subset();
    cout<<ans<<N;
}
