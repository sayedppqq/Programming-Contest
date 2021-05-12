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
#define  MX     200
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

class info
{
    public:
    int u,v,w;
    info(int a,int b,int c)
    {
        u=a;
        v=b;
        w=c;
    }
};

vector<info> graph;
int par[MX];

bool cmp_mx(const info&a,const info&b)
{
    if(a.w>b.w) return true;
    return false;
}
bool cmp_mn(const info&a,const info&b)
{
    if(a.w<b.w) return true;
    else return false;
}

int find_set(int v)
{
    if(v==par[v]) return v;
    return par[v]=find_set(par[v]);
}

int MST_max(int n)
{
    for (int i = 0; i <= n; i++)
        par[i] = i;
    sort(all(graph),cmp_mx);
    int sum=0,cnt=0;
    for(int i=0;i<graph.size();i++)
    {
        int a=find_set(graph[i].u);
        int b=find_set(graph[i].v);
        if(a!=b)
        {
            par[a]=b;
            cnt++;
            sum+=graph[i].w;
        }
        if(cnt==n) break;
    }
    return sum;

}

int MST_min(int n)
{
    for (int i = 0; i <= n; i++)
        par[i] = i;
    sort(all(graph),cmp_mn);
    int sum=0,cnt=0;
    for(int i=0;i<graph.size();i++)
    {
        int a=find_set(graph[i].u);
        int b=find_set(graph[i].v);
        if(a!=b)
        {
            par[a]=b;
            cnt++;
            sum+=graph[i].w;
        }
        if(cnt==n) break;
    }
    return sum;
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        while(1)
        {
            int u,v,w;
            scanf("%d%d%d",&u,&v,&w);
            if(u==0 && v==0 && w==0) break;
            graph.pb(info(u,v,w));
        }

        int maxi=MST_max(n);
        int mini=MST_min(n);

        int tot=maxi+mini;

        printf("Case %d: ",cases++);

        if(tot%2==0) printf("%d\n",tot/2);
        else printf("%d/2\n",tot);

        graph.clear();
    }
}
