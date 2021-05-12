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
#define  MX     1005
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
ll d,m,n,ara[MX],cnt;
ll dp[300][305][15];
ll rec(ll pos,ll sum,ll cnt)
{
    if(cnt==m ){
        if(sum==0) return 1;
        return 0;
    }
    if(cnt>m) return 0;
    if(pos>=n) return 0;
    if(dp[pos][sum][cnt]!=-1) return dp[pos][sum][cnt];
    ll  taken=rec(pos+1,(sum+ara[pos]%d)%d,cnt+1);
    ll ntaken=rec(pos+1,sum%d,cnt);
    dp[pos][sum][cnt]=taken+ntaken;
    return dp[pos][sum][cnt];
}
int main()
{
   //freopen ("output.txt","w",stdout);
   //freopen ("input.txt","r",stdin);
    FIO;
    ll q;
    while(cin>>n>>q)
    {
        if(n==0 && q==0 ) break;
        for(ll i=0;i<n;i++)
        {
            cin>>ara[i];
        }

        cout<<"SET "<<cases++<<":"<<endl;
        int k=0;
        for(ll i=0;i<q;i++)
        {
            k++;
            MEM(dp,-1);
            cin>>d>>m;
            ll ans=rec(0,0,0);
            cout<<"QUERY "<<k<<": "<<ans<<endl;
        }
    }
}
