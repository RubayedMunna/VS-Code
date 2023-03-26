#include<bits/stdc++.h>
using namespace std;

#define ll long long 
#define N '\n'
#define Fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

const ll maxn=1<<21;

string str;
ll n,len;
ll SA[maxn],pos[maxn],tmp[maxn],lcp[maxn];


bool comp(ll i,ll j)
{
    if(pos[i]!=pos[j])
    {
        return pos[i]<pos[j];
    }

    i+=len;
    j+=len;

    return (i<n&&j<n)?pos[i]<pos[j]:i>j;
}

void buildSA(string str)
{
    n=str.size();
    for(ll i=0;i<n;i++)
    {
        SA[i]=i;
        pos[i]=str[i];
    }

    for(len=1;;len*=2)
    {
        sort(SA,SA+n,comp);

        for(ll i=0;i<n-1;i++)
        {
            tmp[i+1]=tmp[i]+comp(SA[i],SA[i+1]);
        }

        for(ll i=0;i<n;i++)
        {
            pos[str[i]]=tmp[i];
        }

        if(tmp[n-1]==n-1)
        {
            break;
        }
    }
}

int main()
{

    string str;
    cin>>str;

    buildSA(str);

    for(ll i=0;i<n;i++)
    {
        cout<<SA[i]<<" ";
    }
    cout<<N;

    return 0;
}