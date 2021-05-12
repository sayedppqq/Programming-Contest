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
#define  MX     5000001
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
ll mod=100000007;
bool marked[MX+5];
vll primes;
void sieve()
{
   marked[0]=marked[1]=true;
   primes.pb(2);
   for(int i=3;i*i<MX;i+=2)
   {
       if(!marked[i])
       {
           for(int j=i*i;j<=MX;j+=i*2)
               marked[j]=true;
       }
   }
   for(int i=3;i<=MX;i+=2)
   {
       if(!marked[i])
        primes.pb(i);
   }
}
int main()
{
   // Fileio
    FIO;
    sieve();
    ll n;
    while(cin>>n && n!=0)
    {
        vpl v;
        ll ans=1;
        for(int i=0;primes[i]<=n;i++)
        {
            ll tot=0,p=primes[i];
            for(ll x=p;x<=n;x*=p)
            {
                ll occ=(n/x);
                tot+=((occ*(n+1LL))-(x*((occ*(occ+1LL)/2LL))));
            }
            v.pb({primes[i],tot});
        }
        for(int i=0;i<SZ(v);i++)
        {
            ans*=((v[i].ss)+1)%mod;
            ans%=mod;
        }
        cout<<ans%mod<<nl;
    }
}
