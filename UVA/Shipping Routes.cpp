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
        cerr.write(names, comma - names) << " is " << arg1 <<" | ";
        __f(comma+1, args...);
    }
#else
    #define debug(...)
#endif
///******************************************START******************************************
int vis[MX],dist[MX];
vii graph[30];
void bfs(int st)
{
    MEM(vis,0);
    MEM(dist,0);
    vis[st]=1;
    queue<int> q;
    q.push(st);
    while(q.size()!=0)
    {
        int u=q.front();
        q.pop();
        for(int i=0;i<graph[u].size();i++)
        {
            int v=graph[u][i];
            if(vis[v]==0)
            {
                vis[v]=1;
                q.push(v);
                dist[v]=dist[u]+1;
            }
        }
    }
}
int main()
{
//   freopen ("output.txt","w",stdout);
//   freopen ("input.txt","r",stdin);
//    FIO;

    int t;
    cin>>t;
    cout<<"SHIPPING ROUTES OUTPUT"<<endl<<endl;
    while(t--)
    {
        cout<<"DATA SET  "<<cases<<endl<<endl;
        int node,edge,qr;
        cin>>node>>edge>>qr;
        map<string,int>value;
        for(int i=0;i<node;i++)
        {
            string ch;
            cin>>ch;
            value[ch]=i;
        }
        for(int i=0;i<edge;i++)
        {
            string a,b;
            cin>>a>>b;
            graph[value[a]].pb(value[b]);
            graph[value[b]].pb(value[a]);
        }
        cases++;
        while(qr--)
        {
            int sz;
            string s,e;
            cin>>sz>>s>>e;
            bfs(value[s]);
            if(vis[value[e]]==0)
                cout<<"NO SHIPMENT POSSIBLE"<<endl;
            else cout<<"$"<<dist[value[e]]*sz*100<<endl;
        }
        cout<<endl;
        for(int i=0;i<30;i++)
        {
            graph[i].clear();
        }
    }
    cout<<"END OF OUTPUT"<<endl;
}
