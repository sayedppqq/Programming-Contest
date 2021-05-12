#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define  FIO        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define  Fileio     freopen("output.txt","w",stdout);freopen("input.txt","r",stdin);
#define  all(v)     v.begin(),v.end()
#define  rall(v)    v.rbegin(),v.rend()
#define  MEM(a,x)   memset(a,x,sizeof(a))
#define  SZ(v)      v.size()
#define  nl         "\n"
#define  bug        cout<<"bug"<<nl;
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
#define  MX     1000006
#define  EPS    1e-12
#define  ss     second
#define  ff     first
using namespace std;
using namespace __gnu_pbds;

template<typename T>
using ordered_set=tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
template<typename T>
using ordered_multiset=tree<T, null_type, less_equal<T>, rb_tree_tag,tree_order_statistics_node_update>;

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
char temp[MX];
const long long MOD[]  = {1000000007LL, 2117566807LL,1000000007LL};
const long long BASE[] = {1572872831LL, 1971536491LL,1000003LL};
long long pwr0[MX],pwr1[MX],HASH0[MX],HASH1[MX];
void init()
{
    pwr0[0]=1;
    for(int i=1;i<MX;i++)
    {
        pwr0[i]=(pwr0[i-1] * BASE[0]) % MOD[0];
    }
}
void Construct(string &s)
{
    HASH0[0]=0;
    for(int i=1;i<=s.size();i++)
    {
        HASH0[i]=(HASH0[i-1] * BASE[0] + s[i-1]) % MOD[0];
    }
}
ll tempHashVal(string &s)
{
    ll h=0;
    for(int i=0;i<SZ(s);i++)
    {
        h+=(s[i]*pwr0[SZ(s)-i-1])%MOD[0];
        h%=MOD[0];
    }
    return h;
}
long long GetForwardHash0(int l,int r)
{
    long long hash0 = (HASH0[r] - HASH0[l-1]* pwr0[r-l+1]) % MOD[0];
    if(hash0<0) hash0+=MOD[0];
    return hash0;
}
int main()
{
    //FIO;
    init();
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        map<int,bool> m;
        map<pii,bool> m2;
        vii v;
        vii hashval(MX);
        while(n--)
        {
            scanf("%s",temp);
            string x=temp;
            if(m[SZ(x)]==false) v.pb(SZ(x));
            m[SZ(x)]=true;
            ll hash_val=tempHashVal(x);
            if(m2[{SZ(x),hash_val}]==false) hashval.pb(hash_val);
            m2[{SZ(x),hash_val}]=true;
        }
        scanf("%s",temp);
        string s=temp;
        Construct(s);
        vll dp(SZ(s)+5,INT_MAX/2);
        dp[0]=0;

        for(int i=0;i<SZ(s);i++)
        {
            for(int j=0;j<SZ(v);j++)
            {
                int r=i;
                int l=i-v[j]+1;
                if(l<0) continue;
                ll cur=GetForwardHash0(l+1,r+1);
                if(m2[{v[j],cur}]==true)
                    dp[i+1]=min(dp[i+1],dp[l]+1);
            }
        }
        printf("Case %d: ",cases++);
        if(dp[SZ(s)]==INT_MAX/2) printf("impossible\n");
        else printf("%d\n", dp[SZ(s)]);
    }













}
