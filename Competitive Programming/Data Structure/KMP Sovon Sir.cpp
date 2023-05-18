#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define N '\n'
#define Fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

class KMP {
private:
    string pattern;
    vector<ll> lps;

    void buildLPS() 
    {
        ll len = 0;
        lps[0] = 0;
        ll i = 1;

        while (i < pattern.size()) 
        {
            if (pattern[i] == pattern[len]) 
            {
                len++;
                lps[i] = len;
                i++;
            } else {
                if (len != 0) 
                {
                    len = lps[len-1];
                } 
                else 
                {
                    lps[i] = 0;
                    i++;
                }
            }
        }
    }

public:
    KMP(string pattern) : pattern(pattern) 
    {
        lps.resize(pattern.size(), 0);
        buildLPS();
    }

    vector<ll> search(string text) 
    {
        vector<ll> matches;
        ll i = 0;
        ll j = 0;

        while (i < text.size()) {
            if (text[i] == pattern[j]) 
            {
                i++;
                j++;
            }

            if (j == pattern.size()) 
            {
                matches.push_back(i - j);
                j = lps[j-1];
            } 
            else if (i < text.size() && text[i] != pattern[j]) 
            {
                if (j != 0) 
                {
                    j = lps[j-1];
                } 
                else 
                {
                    i++;
                }
            }
        }

        return matches;
    }
};

void solve(ll tst)
{
    cout << "Enter Pattern: " << N;
    string pattern;
    getline(cin, pattern);
    KMP kmp(pattern);

    ll numberofsearch;
    cout<<"Enter Number of Query: ";
    cin >> numberofsearch;
    cin.ignore();
    while (numberofsearch--)
    {
        string text;
        cout << "Enter Text: " << N;
        getline(cin, text);
        vector<ll> indexes;
        indexes.resize(text.size() + 10, 0);

        indexes= kmp.search(text);
        cout << "Pattern found at: " << N;
        for(ll it:indexes)
        {
            cout << it << " ";
        }
        cout << N<<N;
    }
}
int main()
{
    ll t = 1;
    //cin>>t;
    ll tst = 0;
    while (t--)
    {
        solve(++tst);
    }
}