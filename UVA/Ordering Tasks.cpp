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
vii v[101];
int vis[101];
vpi kt;
int t=1;
void dfs(int x)
{
    vis[x]=true;
    for(int i=0;i<v[x].size();i++)
    {
        if(vis[v[x][i]]==false)
        {
            t++;
            dfs(v[x][i]);
        }
    }
    t++;
    kt.pb(mp(t,x));
}
int main()
{
   //freopen ("output.txt","w",stdout);
   //freopen ("input.txt","r",stdin);
    FIO;
    int n,m;
    while(cin>>n>>m){
            if(n==0 && m==0) break;
    MEM(vis,0);
    kt.clear();
    for(int i=1;i<=101;i++)
    {
        v[i].clear();
    }
    for(int i=0;i<m;i++)
    {
        int x,y;
        cin>>x>>y;
        v[x].pb(y);
    }
    for(int i=1;i<=n;i++)
    {
        if(vis[i]==false)
        {
            dfs(i);
        }
        t++;
    }
    sort(kt.rbegin(),kt.rend());
    for(auto it:kt)
    {
        cout<<it.ss<<" ";
    }
    cout<<endl;
    }
}
