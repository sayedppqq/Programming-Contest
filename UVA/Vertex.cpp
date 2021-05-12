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
int vis[105];
vii graph[105];
int k;
bool ok;
void dfs(int x)
{
    vis[x]=1;
    for(int i=0;i<graph[x].size();i++)
    {
        int u=graph[x][i];
        if(u==k) ok=true;
        if(vis[u]==0)
        {
            dfs(u);
        }
    }
}
int main()
{
//   freopen ("output.txt","w",stdout);
//   freopen ("input.txt","r",stdin);
    FIO;
    int n;
    while(cin>>n)
    {
        if(n==0) break;
        for(int i=0;i<105;i++)
            graph[i].clear();
        int start;
        while(cin>>start)
        {
            if(start==0) break;
            for(int i=0;;i++)
            {
                int t;
                cin>>t;
                if(t==0) break;
                graph[start].pb(t);
            }
        }
        int q;
        cin>>q;
        while(q--)
        {
            cin>>k;
            MEM(vis,0);
            ok=false;
            dfs(k);
            int cnt=0;
            if(!ok) vis[k]=0;
            vii v;
            for(int i=1;i<=n;i++)
            {
                if(vis[i]==0){
                        cnt++;
                    v.pb(i);
                    }
            }
            cout<<cnt;
            if(cnt!=0) cout<<" ";
            int sz=v.size();
            for(int i=0;i<sz;i++)
            {
                cout<<v[i];
                if(i!=sz-1) cout<<" ";
            }
            cout<<endl;
        }
    }
}
