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
#define  MX     100005
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

int n,m,timer;
vector<int> adj[100005],in_time,low;
vector<pair<int,int>> bridge;
vector<bool> vis;

void dfs(int u,int p)
{
    in_time[u]=low[u]=timer++;
    vis[u]=true;

    for(auto it: adj[u])
    {
        if(it==p) continue;
        if(vis[it])
            low[u]=min(in_time[it],low[u]);
        else
        {
            dfs(it,u);
            low[u]=min(low[u],low[it]);
            if(low[it]>in_time[u])
                bridge.push_back({min(u,it),max(u,it)});
        }
    }
}
void findBridges()
{
    in_time.assign(n+2,0);
    low.assign(n+2,0);
    vis.assign(n+2,false);
    timer=1;
    for(int i=0;i<n;i++)
        if(!vis[i]) dfs(i,-1);
    printf("Case %d:\n",cases++);
    printf("%d critical links\n",SZ(bridge));
    sort(all(bridge));
    for(auto it: bridge) printf("%d - %d\n",it.first,it.second);
}
void CLR()
{
    for(int i=0;i<n+2;i++)
        adj[i].clear();
    in_time.clear();
    low.clear();
    vis.clear();
    bridge.clear();
}
int main()
{
    //FIO;
    //Fileio;
    int t;
    scanf("%d",&t);
    while(t--) {
        //printf("\n");
        scanf("%d",&n);
        for(int i=0,x,y,z;i<n;i++)
        {
            scanf("%d (%d)", &x, &z);
            for(int j=0;j<z;j++)
            {
                scanf("%d",&y);
                adj[x].pb(y);
            }
        }

        findBridges();
        CLR();
    }
}
