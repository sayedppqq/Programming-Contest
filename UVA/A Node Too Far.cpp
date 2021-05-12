#include<bits/stdc++.h>
using namespace std;
#define  FIO        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

#define  all(v)     v.begin(),v.end()
#define MEM(a,x)    memset(a,x,sizeof(a))
#define One(x)      __builtin_popcount(x)
#define Unique(v)    v.erase(unique(v.begin(),v.end()),v.end())
#define pi          acos(-1.0)

#define  ll     long long
#define  pb     push_back
#define  mp     make_pair
#define  pii    pair< int,int >
#define  pll    pair< ll,ll >
#define  vii    vector< int >
#define  vll    vector< ll >
#define  vpi    vector< pii >
#define  MX     100005
#define  EPS    1e-12
#define  ss     second
#define  ff     first

int dx[]={ -2, -2, -1, 1, 2, 2, 1, -1 };
int dy[]={ -1, 1, 2, 2, 1, -1, -2, -2 };
#ifdef ppqq
     #define debug(...) __f(#__VA_ARGS__, __VA_ARGS__)
    template < typename Arg1 >
    void __f(const char* name, Arg1&& arg1){
        cerr << name << " is " << arg1 << std::endl;
    }
    template < typename Arg1, typename... Args>
    void __f(const char* names, Arg1&& arg1, Args&&... args){
        const char* comma = strchr(names+1, ',');
        cerr.write(names, comma - names) << " is " << arg1 <<" | ";
        __f(comma+1, args...);
    }
#else
    #define debug(...)
#endif
///******************************************START******************************************
int vis[MX];
map<int,int>dist;
int ttl,start,m=1;
void bfs(int st,map<int,vii> graph)
{
    dist[st]=0;
    queue<int> q;
    q.push(st);
    while(q.empty()==false)
    {
        int u=q.front();
        q.pop();
        int sz=graph[u].size();
        for(int i=0;i<sz;i++)
        {
            int ch=graph[u][i];
            if(!dist.count(ch))
            {
                dist[ch]=dist[u]+1;
                q.push(ch);
            }
        }
    }
}
int main()
{
//   freopen ("output.txt","w",stdout);
//   freopen ("input.txt","r",stdin);
//    FIO;
    int tc,cases=1;
    while(cin>>tc)
    {
        if(tc==0) break;
        map<int,vii> v;
        for(int i=0;i<tc;i++)
        {
            int a,b;
            cin>>a>>b;
            v[a].pb(b);
            v[b].pb(a);
        }
        while(cin>>start>>ttl)
        {
            if(ttl==0 && start==0) break;
            dist.clear();
            bfs(start,v);
            int ans=0;
            for(auto it:dist)
            {
                if(it.ss>ttl) ans++;
            }
            ans+=v.size()-dist.size();
            printf("Case %d: %d nodes not reachable from node %d with TTL = %d.\n",cases,ans,start,ttl);
            cases++;
        }
    }
}
