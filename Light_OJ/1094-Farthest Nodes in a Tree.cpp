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
vii graph[30005];
int visited[30005];
map<pair<int,int>,int>m;
int maxi;
vpi nudus(30005,mp(0,0));
void dfs(int u)
{
    visited[u]=1;
    for(int i=0;i<graph[u].size();i++)
    {
        int v=graph[u][i];
        if(visited[v]==0)
        {
            visited[v]=1;
            dfs(v);
            int temp=nudus[v].ff+m[{v,u}];
            if(temp>nudus[u].ff) {
                    nudus[u].ss=nudus[u].ff;
                    nudus[u].ff=temp;
            }
            else if(temp>nudus[u].ss)
            {
                nudus[u].ss=temp;
            }
            maxi=max(maxi,nudus[u].ss+nudus[u].ff);
        }
    }
}
int main()
{
   //freopen ("output.txt","w",stdout);
   //freopen ("input.txt","r",stdin);
    FIO;
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        for(int i=0;i<30005;i++)
        {
            nudus[i].ss=0;
            nudus[i].ff=0;
        }
        for(int i=0;i<30005;i++)
        {
            graph[i].clear();
        }
        MEM(visited,0);
        for(int i=0;i<n-1;i++)
        {
            int x,y,z;
            cin>>x>>y>>z;
            graph[x].pb(y);
            graph[y].pb(x);
            m[{x,y}]=z;
            m[{y,x}]=z;
        }
        dfs(0);
        cout<<"Case "<<cases++<<": "<<maxi<<endl;
        maxi=0;
        m.clear();


    }
}
