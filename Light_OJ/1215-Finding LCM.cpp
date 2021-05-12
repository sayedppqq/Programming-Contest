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
#define  MX     1000000
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
bool marked[MX+5];
vii primes;
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
    //FIO;
    //Fileio;
    sieve();
    int t;
    cin>>t;
    while(t--)
    {
        ll a,b;
        ll L,K,c=1;
        cin>>a>>b>>L;

        vii v(MX+5,0),used;
        map<ll,bool> U;

        for(int j=0;j<2;j++)
        {
            ll n=a,k;
            if(j%2) n=b;
            k=n;
            for(int i=0;primes[i]*primes[i]<=n;i++)
            {
                int p=primes[i];
                if(k%p==0)
                {
                    int cnt=0;
                    while(k%p==0) cnt++,k/=p;
                    v[p]=max(v[p],cnt);
                    used.pb(p);
                }
            }
            if(k>1) v[k]=max(1,v[k]),used.pb(k);
        }

        K=L;
        bool ok=true;
        for(int i=2;i*i<=K;i++)
        {
            int p=i;
            if(K%p==0)
            {
                int cnt=0;
                while(K%p==0) K/=p,cnt++;
                U[p]=true;
                if(cnt>v[p]) c*=powr(p,cnt);
                else if(cnt!=v[p])
                {
                    ok=false;
                    break;
                }
            }
        }
        if(K>1LL && ok)
        {
            U[K]=true;
            if(K>MX || v[K]==0) c*=K;
            else if(v[K]>1) ok=false;
        }

        for(auto it: used)
        {
            if(U[it]==0)
            {
                ok=false;
                break;
            }
        }
        if(!ok) cout<<"Case "<<cases++<<": impossible\n";
        else cout<<"Case "<<cases++<<": "<<c<<nl;
    }

















}
