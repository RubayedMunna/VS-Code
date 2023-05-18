#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define N '\n'
#define Fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

/// Pattern ,        Text
vector<int>RabinKarp(string const& s, string const& t) {
    const int p = 37;
    const int m = 1e9 + 7;
    int ls = (int)s.size(), lt = (int)t.size();
    int T =lt;
    vector<long long> p_pow(max(ls, lt));
    p_pow[0] = 1;
    for (int i = 1; i < (int)p_pow.size(); i++)
        p_pow[i] = (p_pow[i-1] * p) % m;

    vector<long long>h(lt + 1, 0);
    for (int i = 0; i < lt; i++)
        h[i+1] = (h[i] + (t[i] - 'a' + 1) * p_pow[i]) % m;
    long long h_s = 0;
    for (int i = 0; i < ls; i++)
        h_s = (h_s + (s[i] - 'a' + 1) * p_pow[i]) % m;

    vector<int>occurences;
    for (int i = 0; i + ls - 1 < T; i++) {
        long long cur_h = (h[i+ls] + m - h[i]) % m;
        if (cur_h == h_s * p_pow[i] % m)
            occurences.emplace_back(i);
    }
    return occurences;
}


int main()
{
    string Text;
    string Pattern;
    cout << "Enter The Text: ";
    getline(cin, Text);
    cout<<"Enter Number of Query: "<<N;
    ll query;
    cin>>query;
    while(query--)
    {
        cout << "Enter The Pattern: ";
        getline(cin, Pattern);
        vector<int>found = RabinKarp(Pattern,Text);
        
        cout << "The Number of occurrences of \"" << Pattern << "\" is " << found.size() << N;
        
        cout<<"The Indexes Are : ";
        for(int i=0;i<found.size();i++)
        {
            cout<<found[i]<<" ";
        }
        cout << N;
    }
}
