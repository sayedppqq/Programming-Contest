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
#define  MX     20005
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
int n,m,grp[MX],cnt;
vii adj[MX],rev[MX];
stack<int> st;
bool vis[MX],ind[MX],out[MX];
void dfs1(int u)
{
    vis[u]=true;
    for(auto it: adj[u])
        if(!vis[it]) dfs1(it);
    st.push(u);
}
void dfs2(int u)
{
    grp[u]=cnt;
    vis[u]=true;
    for(auto it: rev[u]){
        if(!vis[it]) dfs2(it);
    }
}
void SCC()
{
    for(int i=1;i<=n;i++)
        if(!vis[i]) dfs1(i);

    for(int i=1;i<=n;i++) vis[i]=false;

    while(!st.empty())
    {
        int u=st.top();
        st.pop();
        if(!vis[u])
        {
            cnt++;
            dfs2(u);
        }
    }
}
void dfs3(int u,int p)
{
    vis[u]=true;
    for(auto it: adj[u])
    {
        if(grp[u]!=grp[it])
        {
            ind[grp[it]]=true;
            out[grp[u]]=true;
        }
        if(vis[it]) continue;
        dfs3(it,u);
    }
}
void CLR()
{
    for(int i=0;i<=n+2;i++)
    {
        adj[i].clear();
        rev[i].clear();
        ind[i]=false;
        out[i]=false;
        vis[i]=false;
        grp[i]=0;
    }
    while(!st.empty()) st.pop();
    cnt=0;
}
int main()
{
    //FIO;
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        for(int i=0,x,y;i<m;i++)
        {
            scanf("%d%d",&x,&y);
            adj[x].pb(y);
            rev[y].pb(x);
        }
        SCC();
        for(int i=1;i<=n;i++) vis[i]=false;
        for(int i=1;i<=n;i++)
        {
            if(!vis[i])
            {
                dfs3(i,-1);
            }
        }
        int rgt=0,lft=0;
        for(int i=1;i<=cnt;i++)
        {
            if(!ind[i]) rgt++;
            if(!out[i]) lft++;
        }
        debug(lft,rgt);
        int res=max(rgt,lft);
        if(cnt==1) res=0;
        printf("Case %d: %d\n",cases++,res);

        CLR();
    }













}
