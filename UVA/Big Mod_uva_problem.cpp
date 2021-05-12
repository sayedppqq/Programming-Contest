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
ll b,p,m;
map<ll,ll>dp;
ll bigmod(ll b,ll p)
{
    if(p==0) return 1;
    if(dp[p]!=0) return dp[p];
    if(p%2==0)
    {
        ll aa=bigmod(b,p/2);
        dp[p]=((aa%m)*(aa%m))%m;
        return dp[p];
    }
    else
    {
        ll a=bigmod(b,p-1);
        dp[p]=((b%m)*(a%m))%m;
        return dp[p];
    }
}
int main()
{
   //freopen ("output.txt","w",stdout);
   //freopen ("input.txt","r",stdin);
    FIO;
    while(cin>>b>>p>>m)
    {
        ll ans=bigmod(b,p);
        dp.clear();
        cout<<ans<<endl<<endl;
    }
}

