#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define  FIO        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define  Fileio     freopen("output.txt","w",stdout);freopen("input.txt","r",stdin);
#define  all(v)     v.begin(),v.end()
#define  rall(v)    v.rbegin(),v.rend()
#define  MEM(a,x)   memset(a,x,sizeof(a))
#define  SZ(v)      v.size()
#define  nl         "\n"
#define  bug        cout<<"bug"<<nl;
#define  pi         acos(-1.0)
#define  ll     long long
#define  pb     push_back
#define  mp     make_pair
#define  pii    pair< int,int >
#define  pll    pair< ll,ll >
#define  vii    vector< int >
#define  vll    vector< ll >
#define  vpi    vector< pii >
#define  vpl    vector<pll>
#define  MX     250
#define  EPS    1e-12
#define  ss     second
#define  ff     first
using namespace std;
using namespace __gnu_pbds;

template<typename T>
using ordered_set=tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
template<typename T>
using ordered_multiset=tree<T, null_type, less_equal<T>, rb_tree_tag,tree_order_statistics_node_update>;

inline ll powr(int a,int b){ll res=1;while(b){if(b&1) res*=a;a*=a;b/=2;}return res;}
int cases=1;

#ifdef ppqq
     #define debug(...) __f(#__VA_ARGS__, __VA_ARGS__)
    template < typename Arg1 >
    void __f(const char* name, Arg1&& arg1){
        cerr << name << " is " << arg1 << std::endl;
    }
    template < typename Arg1, typename... Args>
    void __f(const char* names, Arg1&& arg1, Args&&... args){
        const char* comma = strchr(names+1, ',');
        cerr.write(names, comma - names) << " is " << arg1 <<"  ";
        __f(comma+1, args...);
    }
#else
    #define debug(...)
#endif

///******************************************START******************************************
int dis[MX][MX];
bool in[MX][MX];
const int inf=0x3f3f3f3f;
vpi adj[MX];

void SPFA(int src,int n,int len)
{
    MEM(dis,inf);
    MEM(in,false);

    queue<pii> q;
    q.push({src,0});
    in[src][0]=true;
    dis[src][0]=0;

    while(!q.empty())
    {
        pair<int,int> u=q.front();
        q.pop();
        in[u.ff][u.ss]=false;
        for(auto it: adj[u.ff])
        {
            if(u.ss+1<=len && dis[it.ff][u.ss+1]>dis[u.ff][u.ss]+it.ss)
            {
                dis[it.ff][u.ss+1]=dis[u.ff][u.ss]+it.ss;
                if(!in[it.ff][u.ss+1])
                {
                    q.push({it.ff,u.ss+1});
                    in[it.ff][u.ss+1]=true;
                }
            }
        }
    }
}
void CLR(int n)
{
    for(int i=0;i<=n;i++) adj[i].clear();
}
int main()
{
    FIO;
    Fileio
    int t;
    cin>>t;
    while(t--)
    {
        int n,m,q;
        string s,sx;
        map<string,int> mpp;
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            cin>>s;
            mpp[s]=i;
        }
        cin>>m;
        for(int i=0,w;i<m;i++)
        {
            cin>>s>>sx>>w;
            adj[mpp[s]].pb({mpp[sx],w});
        }

        s="Calgary";sx="Fredericton";

        cout<<"Scenario #"<<cases++<<nl;
        cin>>q;
        while(q--)
        {
            int len;
            cin>>len;
            len++;
            if(len>n) len=n;
            SPFA(mpp[s],n,len);
            int mini=inf;
            for(int i=1;i<=len;i++) mini=min(mini,dis[mpp[sx]][i]);
            if(mini==inf) cout<<"No satisfactory flights\n";
            else cout<<"Total cost of flight(s) is $"<<mini<<nl;
        }
        cout<<nl;
        CLR(n);

    }
}
