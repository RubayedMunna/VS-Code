#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define N '\n'
#define Fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

const ll maxn = 26;

class Trie{
public:
    Trie():cnt(0)
    {
        for (ll i = 0; i < maxn;i++)
        {
            next[i] = nullptr;
        }
    }
    void insert(const string& s)
    {
        Trie *cur = this;

        for(ll i=0;i<s.length();i++)
        {
            ll c = s[i] - 'a';
            if(cur->next[c]==nullptr)
            {
                cur -> next[c] = new Trie();
            }
            cur = cur->next[c];
        }
        ++cur->cnt;
    }

    ll query(const string &s)
    {
        Trie *cur = this;
        for (ll i = 0; i < s.length();++ i)
        {
            ll c = s[i] - 'a';
            if(cur->next[c]==nullptr)
            {
                return 0;
            }
            cur = cur->next[c];
        }
        return cur->cnt;
    }
private:
    ll cnt;
    Trie *next[maxn];
};

int main()
{
    Trie trie;

    trie.insert("hello");
    trie.insert("world");
    trie.insert("hello");
    trie.insert("world");

    cout << "Number of occurrences of \"hello\": " << trie.query("hello") << N;

    cout << "Number of occurrences of \"world\": " << trie.query("world") << N;

    cout << "Number of occurrences of \"hi\": " << trie.query("hi") << N;
    return 0;
}