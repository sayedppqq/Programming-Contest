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
#define  EPS    1e-8
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
int main()
{
//   freopen ("output.txt","w",stdout);
//   freopen ("input.txt","r",stdin);
    FIO;
    int n;
    while(cin>>n)
    {
        vii graph[50];
        double d[50];
        for(int i=0;i<n;i++)
        {
            char p;
            double point;
            string con;
            cin>>p>>point>>con;
            d[p-'A'+1]=point;
            for(int i=0;i<con.size();i++)
            {
                int x;
                if(con[i]=='*') x=0;
                else x=con[i]-'A'+1;
                graph[x].pb(p-'A'+1);
            }
        }
        int dist[50],t;
        double maxi=0.0;
        MEM(dist,0);
        queue<int> q;
        dist[0]=1;
        q.push(0);
        while(q.size())
        {
            int u=q.front();
            q.pop();
            for(int i=0;i<graph[u].size();i++)
            {
                int v=graph[u][i];
                if(dist[v]==0)
                {
                    dist[v]=dist[u]+1;
                    q.push(v);
                }
            }
            if(u>0)
            {
               double val=d[u]*pow(0.95,dist[u]-2);
               if(val>maxi || (fabs(val-maxi)<EPS && u<t))
               {
                   maxi=val;
                   t=u;
               }
            }
        }
        char a=t+'A'-1;
        cout<<"Import from "<<a<<endl;
    }
}
