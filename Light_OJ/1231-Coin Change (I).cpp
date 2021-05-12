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
ll n,k,dp[105][1005];
int taka[105],amount[105];
ll rec(int pos,int sum)
{   if(pos>=n)
    {
        if(sum==0) return 1;
        return 0;
    }
    if(sum<0) return 0;
    if(dp[pos][sum]!=-1) return dp[pos][sum];
    ll tot=0;
    for(int i=0;i<=amount[pos];i++)
    {
        tot=(tot+rec(pos+1,sum-(taka[pos]*i)))% 100000007;
    }
    dp[pos][sum]=tot;
    return tot;
}
int main()
{
//   freopen ("output.txt","w",stdout);
//   freopen ("input.txt","r",stdin);
    FIO;
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        MEM(taka,0);
        MEM(amount,0);
        MEM(dp,-1);
        for(int i=0;i<n;i++)
        {
            cin>>taka[i];
        }
        for(int i=0;i<n;i++)
        {
            cin>>amount[i];
        }
        cout<<"Case "<<cases++<<": "<<rec(0,k)% 100000007<<endl;
    }
}
