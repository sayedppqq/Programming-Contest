#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define  FIO        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define  all(v)     v.begin(),v.end()
#define  rall(v)    v.rbegin(),v.rend()
#define  MEM(a,x)   memset(a,x,sizeof(a))
#define  SZ(v)      v.size()
#define  bug        cout<<"bug"<<endl;
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

void Fileio(){freopen ("output.txt","w",stdout);freopen ("input.txt","r",stdin);}
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
int dist[5][5005];
const int inf = 5000000;
vector<vpi> adj;
void bfs()
{
    MEM(dist,inf);
    priority_queue<pii,vpi,greater<pii>> pq;
    dist[1][1]=0;
    pq.push({0,1});
    while(!pq.empty())
    {
        int u=pq.top().ss;
        int dd=pq.top().ff;
        pq.pop();
        for(auto it:adj[u])
        {
            int cur_node=it.ff;
            int cur_cost=it.ss;
            int d=cur_cost+dd;
            if(d<dist[1][cur_node])
            {
                dist[2][cur_node]=dist[1][cur_node];
                dist[1][cur_node]=d;
                pq.push({d,cur_node});
            }
            else if(d>dist[1][cur_node]   &&   d<dist[2][cur_node])
            {
                dist[2][cur_node]=d;
                pq.push({d,cur_node});
            }
        }
    }
}
int main()
{
    FIO;
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;

        adj.assign(n+1,vpi());

        for(int i=0;i<m;i++)
        {
            int x,y,z;
            cin>>x>>y>>z;
            adj[x].pb({y,z});
            adj[y].pb({x,z});
        }

        bfs();

        cout<<"Case "<<cases++<<": "<<dist[2][n]<<"\n";

    }
}
