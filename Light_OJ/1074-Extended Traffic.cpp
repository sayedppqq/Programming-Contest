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
int n,m,q;
int dis[205],A[205];
bool visited[205];
vector<pair<int,int>> adj[205];
int cube(int x) { return x*x*x; }
void relax(int u,int v,int w)
{
    if(dis[v]>dis[u]+w)
        dis[v]=dis[u]+w;
}
void dfs(int u)
{
    visited[u]=true;
    for(auto it: adj[u])
    {
        if(!visited[it.ff])
            dfs(it.ff);
    }
}
void bellman_ford()
{
    for(int i=1;i<202;i++) dis[i]=INT_MAX/3;
    dis[1]=0;

    for(int i=1;i<n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            for(auto it: adj[j])
            {
                int u=j,v=it.ff,w=it.ss;
                relax(u,v,w);
            }
        }
    }

}
void CLR(int sz)
{
    for(int i=0;i<=sz;i++)
    {
        adj[i].clear();
        A[i]=0;
        visited[i]=false;
    }
}
int main()
{
    //FIO;
    //Fileio;
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%d",&A[i]);
        scanf("%d",&m);

        for(int i=0,x,y;i<m;i++)
        {
            scanf("%d%d",&x,&y);
            int w=cube(A[y]-A[x]);
            adj[x].pb({y,w});
        }

        bellman_ford();
        dfs(1);

        printf("Case %d:\n",cases++);
        int q;
        cin>>q;
        while(q--)
        {
            int k;
            scanf("%d",&k);
            if(dis[k]<3 || !visited[k] || dis[k]==INT_MAX/3) printf("?\n");
            else printf("%d\n",dis[k]);
        }

        CLR(n);
    }
}
