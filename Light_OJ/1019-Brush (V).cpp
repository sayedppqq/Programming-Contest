#include<bits/stdc++.h>
using namespace std;
#define  FIO        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define  all(v)     v.begin(),v.end()
#define  rall(v)    v.rbegin(),v.rend()
#define MEM(a,x)    memset(a,x,sizeof(a))
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
vpi adj[MX];
priority_queue<pll,vector<pll>,greater<pll>>pq;
ll dist[MX];
int par[MX];
void bfs(int u,int n)
{
    pq.push(mp(0,u));
    for(int i=1;i<=n;i++) dist[i]=LLONG_MAX,par[i]=0;
    dist[u]=0;
    while(!pq.empty())
    {
        int v=pq.top().ss;
        pq.pop();
        for(int i=0;i<adj[v].size();i++)
        {
            int cur_node=adj[v][i].ff;
            int cur_weight=adj[v][i].ss;
            if(cur_weight+dist[v]<dist[cur_node])
            {
                dist[cur_node]=cur_weight+dist[v];
                par[cur_node]=v;
                pq.push(mp(dist[cur_node],cur_node));
            }
        }
    }
}
void CLR(int n)
{
    for(int i=0;i<n+2;i++) adj[i].clear();
    while(!pq.empty()) pq.pop();
}
int main()
{
    FIO;
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        for(int i=0;i<m;i++)
        {
            int x,y,z;
            cin>>x>>y>>z;
            adj[x].pb(mp(y,z));
            adj[y].pb(mp(x,z));
        }
        bfs(1,n);
        cout<<"Case "<<cases++<<": ";
        if(dist[n]==LLONG_MAX)
            cout<<"Impossible\n";
        else cout<<dist[n]<<"\n";

        CLR(n);
    }
}

