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
        cerr.write(names, comma - names) << " is " << arg1 <<" | ";
        __f(comma+1, args...);
    }
#else
    #define debug(...)
#endif
///******************************************START******************************************
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
bool cmp(pair<int,int> a,pair<int,int> b)
{
    if(a.first!=b.first) return a.first<b.first;
    else return (a.second>b.second);
}
int main()
{
   //freopen ("output.txt","w",stdout);
   //freopen ("input.txt","r",stdin);
    FIO;
    sieve();
    vpi nod;
    for(int i=1;i<=1000;i++)
    {
        int n=i;
        int div=1;
        for(int j=0;primes[j]*primes[j]<=n;j++)
        {
            if(n%primes[j]==0)
            {
                int cnt=1;
                while(n%primes[j]==0)
                {
                    n/=primes[j];
                    cnt++;
                }
                div*=cnt;
            }
        }
        if(n!=1) div*=2;
        nod.pb(mp(div,i));
    }
    sort(nod.begin(),nod.end(),cmp);
    int q;
    cin>>q;
    while(q--)
    {
        int n;
        cin>>n;
        cout<<"Case "<<cases<<": "<<nod[n-1].ss<<endl;
        cases++;
    }
}
