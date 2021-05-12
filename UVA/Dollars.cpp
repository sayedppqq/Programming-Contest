
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
int value[11]={5,10,20,50,500,100,200,1000,2000,5000,10000};
ll dp[15][30005];
float ki;
ll cnt=0;
ll check;
ll dollar(int pos,int sum)
{
    if(sum==check) return 1;
    if(sum>check) return 0;
    if(pos>=11) return 0;
    if(dp[pos][sum]!=-1) return dp[pos][sum];
    ll taken=0,ntaken=0;
    taken=dollar(pos,sum+value[pos]);
    ntaken=dollar(pos+1,sum);
    ll tot=ntaken+taken;
    dp[pos][sum]=tot;
    return dp[pos][sum];
}
int main()

{
//   freopen ("output.txt","w",stdout);
//   freopen ("input.txt","r",stdin);
//    FIO;
    while(cin>>ki)
    {
        MEM(dp,-1);
        if(ki==0.00)
            break;
        check=static_cast<int>(ki*100+.5);
        ll result=dollar(0,0);
        printf("%6.2f%17lld\n",ki,result);
    }
}
