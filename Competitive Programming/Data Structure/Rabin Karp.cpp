#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define N '\n'
#define Fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

const ll mod=1e9+7;
vector<ll>hash_text,MI,power;
ll len_text,len_pattern;
ll Bin_Expo(ll a,ll b)
{
    if(b==0)
    {
        return 1;
    }
    
    ll x=Bin_Expo(a,b/2);

    ll y=(x*x)%mod;
  
    if(b%2)
    {
        y=(y*a)%mod;
    }
    return y;
}

void Hashing_Text(string text)
{
    ll n=len_text=text.size();
    hash_text.assign(n+10,0);
    MI.assign(n+10,0);
    power.assign(n+10,0);


    ll d=1;
    ll mm=0;
    hash_text[0]=0;

    for(ll i=0;i<n;i++)
    {
        power[i]=d;
        ll zz=((text[i]-48)*d) % mod;
        mm=(mm+zz)%mod;

        hash_text[i]=mm;

        d=(d*97)%mod;
    }

    MI[0]=1;

    for(ll i=1;i<n;i++)
    {
        MI[i]=Bin_Expo(power[i],mod-2);
    }

}

bool Find_Pattern(string Pattern)
{
    ll n=len_pattern=Pattern.size();
    ll hash_pat=0;
    ll d=1;

    for(ll i=0;i<n;i++)
    {
        ll zz=((Pattern[i]-48)*d)%mod;
        hash_pat=(hash_pat+zz)%mod;

        d=(d*97)%mod;
    }

    for(ll i=0;i<len_text-len_pattern+1;i++)
    {
        ll xx;
        if(i==0)
        {
            xx=hash_text[i+len_pattern-1];
            if(xx==hash_pat)
            {
                return true;
            }
        }
        else 
        {
            xx=hash_text[i+len_pattern-1]-hash_text[i-1];

            if(xx<=0)
            {
                xx=xx+mod;
            }
            xx=(xx*MI[i])%mod;
            if(xx==hash_pat)
            {
                return true;
            }
        }
    }
    return false;
}

int main()
{

    string str;
    cin>>str;

    Hashing_Text(str);

    for(ll i=0;i<str.size();i++)
    {
        cout<<hash_text[i]<<" ";
    }
    cout<<N;

    ll q;
    cin>>q;
    while(q--)
    {
        string pattern;
        cin>>pattern;

        if(Find_Pattern(pattern))
        {
            cout<<"Pattern Found in Text"<<N;
        }
        else 
        {
            cout<<"Pattern not Found in Text"<<N;
        }
    }

    return 0;
}