#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define N '\n'

#define FOR(i,a,b) for (int i=(a);i<(b);i++)
#define RFOR(i,a,b) for (int i=(b)-1;i>=(a);i--)
#define REP(i,n) for (int i=0;i<(n);i++)
#define RREP(i,n) for (int i=(n)-1;i>=0;i--)

#define inf INT_MAX/3
#define INF INT_MAX/3
#define PB push_back
#define pb push_back
#define MP make_pair
#define mp make_pair
#define ALL(a) (a).begin(),(a).end()
#define all(a) (a).begin(),(a).end()
#define SET(a,c) memset(a,c,sizeof a)
#define CLR(a) memset(a,0,sizeof a)
#define PII pair<int,int>
#define pii pair<int,int>
#define pcc pair<char,char>
#define pic pair<int,char>
#define pci pair<char,int>
#define VS vector<string>
#define VI vector<int>
#define debug(x) cout<<#x<<": "<<x<<endl
#define DEBUG(x) cout<<#x<<": "<<x<<endl
#define MIN(a,b) (a>b?b:a)
#define MAX(a,b) (a>b?a:b)
#define PI acos(-1.0)
#define INFILE() freopen("in0.txt","r",stdin)
#define OUTFILE()freopen("out0.txt","w",stdout)
#define LL long long
#define ll long long
#define ULL unsigned long long
#define ull unsigned long long
#define eps 1e-14
#define MOD 1000000007
#define FST first
#define SEC second
//#define PI 3.14159265
template<typename T>inline string toString(T a)
{
    ostringstream os("");
    os<<a;
    return os.str();
}
template<typename T>inline ll toLong(T a)
{
    ll res;
    istringstream os(a);
    os>>res;
    return res;
}
//MATHEMATICS
template<typename T>inline T  S(T a)
{
    return a*a;
}
template<typename T>inline T gcd(T a, T b)
{
    if (b == 0)return a;
    else return gcd(b, a % b);
}
template<typename T>inline ull bigmod(T a, T b, T m)
{
    if (b == 0)return 1;
    else if (b % 2 == 0)return S(bigmod(a, b / 2, m)) % m;
    else return (a % m*bigmod(a, b - 1, m)) % m;
}
template<typename T>inline VS parse(T str)
{
    VS res;
    string s;
    istringstream os(str);
    while(os>>s)res.pb(s);
    return res;
}
template<typename T>inline ull  dist(T A,T B)
{
    ull res=(A.x-B.x)*(A.x-B.x)+(A.y-B.y)*(A.y-B.y);
    return res;
}
template<typename T>inline double cosAngle(T a,T b,T c)
{
    double res=a*a+b*b-c*c;
    res=res/(2*a*b);
    res=acos(res);
    return res;
}
template<typename T>inline T power(T base,int po)
{
    T res=1;
    if(base==0)return 0;
    FOR(i,0,po)res*=base;
    return res;
}
//BIT
template<typename T>inline bool isOn(T mask,T pos)
{
    return mask&(1<<pos);
}
template<typename T>inline int Off(T mask,T pos)
{
    return mask^(1<<pos);
}
template<typename T>inline int On(T mask,T pos)
{
    return mask|(1<<pos);
}

#define Mx 50005
vector<ll> g[Mx];


int vis[Mx];
int arti[Mx];
int st[Mx];
int low[Mx];
int T;
struct Z{

    PII p;
    Z(){}
    Z(int _x, int _y)
    {
        p.FST=MIN(_x,_y);
        p.SEC=MAX(_x,_y);
    }
};



bool operator < (Z A , Z B)
{
    return A.p<B.p;
}
vector<Z>bridge;

void tarjan(int u , int p)
{
    vis[u]=1;
    st[u]=low[u]=++T;

    int child=0;
    FOR(i,0,g[u].size())
    {

        int x=g[u][i];
        if(x!=p){
            if(!vis[x])
            {
                tarjan(x,u);
                child++;
                low[u]=min(low[u],low[x]);

                if(  st[u]<low[x] )bridge.PB(Z(x,u) );
            }
            else   //if( vis[x]==1  )
            {
                low[u]=min(low[u],st[x]);
            }
        }
        // else low[u]=min(low[u],low[x]);
    }

}



int main()
{
    int i,j,k,n,m,x,y;
    int ks,cas;
    cin>>ks;
    FOR(cas,1,ks+1)
    {
        // Initialize
///        scanf("%d",&n);
        // input--> number of node

        // input--> number of edge

        FOR(i,0,n+1)g[i].clear();
        SET(vis,0);
        SET(st,0);
        SET(low,0);
        bridge.clear();
        T=0;
        /// Input Graph

        for(int i=0;i<edge;i++)
        {
            cin>>x>>y;
            g[x].push_back(y);
            g[y].push_back(x);
        }
//        FOR(i,0,n)
//        {
//            scanf("%d",&x);
//            scanf(" (%d)",&m);
//            FOR(j,0,m)
//            {
//                scanf("%d",&y);
//                g[x].PB(y);
//
//            }
//        }




        int res=0;

        FOR(i,0,n)
        {
            if(!vis[i])tarjan(i,-1);
        }

        SET(vis,0);

        sort(ALL(bridge));
        printf("Case %d:\n",cas);
        printf("%d critical links\n",(int)bridge.size());
        FOR(i,0,bridge.size())
        {
            printf("%d - %d\n",bridge[i].p.FST,bridge[i].p.SEC);
        }

    }
}
