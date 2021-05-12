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
int n;
int dp[1005][3005];
vpi v;
int rec(int pos,int load)
{

    if(pos<0) return 0;
    if(load>3000) return 0;
    if(dp[pos][load]!=-1) return dp[pos][load];
    int taken=0,ntaken=0;
    if(load<=v[pos].ss)
    taken=rec(pos-1,load+v[pos].ff)+1;
    ntaken=rec(pos-1,load);
    dp[pos][load]=max(taken,ntaken);

    return dp[pos][load];
}
int main()
{
//   freopen ("output.txt","w",stdout);
//   freopen ("input.txt","r",stdin);
//    FIO;
    while(cin>>n)
    {
        if(n==0) break;
        MEM(dp,-1);
        v.clear();
        for(int i=0;i<n;i++)
        {
            int x,y;
            cin>>x>>y;
            v.pb(mp(x,y));
        }
        cout<<rec(n-1,0)<<endl;
    }
}
