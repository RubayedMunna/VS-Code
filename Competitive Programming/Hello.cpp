#include<bits/stdc++.h>
using namespace std;

#define ll long long 
#define N '\n'
#define Fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

const ll maxn=1<<21;

string Text;
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

void buildSA(string Text)
{
    n=Text.size();
    for(ll i=0;i<n;i++)
    {
        SA[i]=i;
        pos[i]=Text[i];
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
            pos[Text[i]]=tmp[i];
        }

        if(tmp[n-1]==n-1)
        {
            break;
        }
    }
}

ll Search(string Pat)
{
    ll m=Pat.size();

    ll l=0;
    ll r=n-1;

    //cout<<l<<" "<<r<<N;

    

    while(l<=r)
    {
        ll mid=(l+r)/2;
        string str=Text.substr(SA[mid],m);
        ll chk=Pat.compare(str);
        //cout<<mid<<" "<<SA[mid]<<" "<<str<<" "<<chk<<N;
        if(chk<0)
        {
            r=mid-1;
        }
        else if(chk>0)
        {
            
            l=mid+1;
        }
        else 
        {
            return SA[mid];
        }
    }
    return -1;
}


int main()
{

    cout<<"Enter Text"<<N;

    cin>>Text; Text=Text+"$";

    buildSA(Text);

    for(ll i=0;i<n;i++)
    {
        cout<<SA[i]<<" ";
    }
    cout<<N;

    cout<<"Enter Number of Queries"<<N;
    ll q;
    cin>>q;
    while(q--)
    {
        string Pat;
        cin>>Pat;

        ll idx=Search(Pat);


        cout<<idx<<N;

        if(idx==-1)
        {
            cout<<"Pattern not found"<<N;
        }
        else 
        {
            cout<<"Pattern found at "<<idx<<" th index"<<N;
        }
    }
    return 0;
}