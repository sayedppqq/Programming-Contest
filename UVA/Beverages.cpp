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

int cases=1;

///******************************************START******************************************
int vis[105];

vii graph[105];
int main()
{
//   freopen ("output.txt","w",stdout);
//   freopen ("input.txt","r",stdin);
    FIO;
    int q;
    while(cin>>q)
    {
        MEM(vis,0);
        for(int i=0;i<105;i++)
            graph[i].clear();
        map<string,int>m1;
        map<int,string>m2;
        vii order;
        for(int i=1;i<=q;i++)
        {
            string s;
            cin>>s;
            m1[s]=i;
            m2[i]=s;
        }
        int n;
        cin>>n;
        vii ind;
        ind.resize(q+1);
        for(int i=0;i<n;i++)
        {
            string x,y;
            cin>>x>>y;
            ind[m1[y]]++;
            graph[m1[x]].pb(m1[y]);

        }
        for(int i=1;i<=q;i++)
        {
            if(ind[i]==0 && vis[i]==0)
            {
                vis[i]=1;
                order.pb(i);
                for(int j=0;j<graph[i].size();j++)
                {
                    ind[graph[i][j]]--;
                }
                i=0;
            }
        }
        cout<<"Case #"<<cases++<<": Dilbert should drink beverages in this order: ";
//        while(!st.empty())
//        {
//            cout<<m2[st.top()];
//            if(st.size()!=1) cout<<" ";
//            st.pop();
//        }
        int sz=order.size();
        for(int i=0;i<sz;i++)
        {
            if(i==sz-1) cout<<m2[order[i]]<<".";
            else cout<<m2[order[i]]<<" ";
        }
        cout<<endl;
        cout<<endl;
    }
}
