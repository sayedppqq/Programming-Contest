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
#define  vii    vector< int >
#define  vll    vector< ll >
#define  vpi    vector< pair< int,int > >
#define  vpl    vector< pair< ll,ll > >
#define  MX     100005
#define  EPS    1e-12
#define  ss     second
#define  ff     first
#define  pf(xx) printf("%d",xx);
#define  pfl(xx) printf("%lld",xx);
inline int sf(){int aaa;scanf("%d",&aaa);return aaa;}
inline ll sfl(){ll aaa;scanf("%lld",&aaa);return aaa;}
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
vii v;
const int inf=200000;
vpl tree(400005);
void build(ll node,ll s,ll e)
{
    if(s==e) tree[node].ff=v[s-1];
    else
    {
        ll mid=(s+e)/2;
        build(2*node,s,mid);
        build(2*node+1,mid+1,e);
        tree[node].ff=tree[2*node].ff+tree[2*node+1].ff;
    }
}
ll query(ll node,ll s,ll e,ll l,ll r,ll carry=0)
{
    if(l>r || e<l || s>r) return 0;
    if(s>=l && e<=r)
    {
        return tree[node].ff+carry*(e-s+1);
    }
    ll mid=(s+e)/2;
    ll a=query(2*node,s,mid,l,r,carry+tree[node].ss);
    ll b=query(2*node+1,mid+1,e,l,r,carry+tree[node].ss);
    return a+b;
}
void update(ll node,ll s,ll e,ll left,ll right,ll value)
{
    if(left>right || left>e || right<s) return;
    if(left<=s && right>=e)
    {
        tree[node].ff+=(value*((e-s)+1));
        tree[node].ss+=value;

        return;
    }
    ll mid=(s+e)/2;
    update(2*node,s,mid,left,right,value);
    update(2*node+1,mid+1,e,left,right,value);
    tree[node].ff=tree[node*2].ff+tree[node*2+1].ff+(e-s+1)*tree[node].ss;
}
int main()
{
//   freopen ("output.txt","w",stdout);
//   freopen ("input.txt","r",stdin);
//    FIO;
    ll t;
    cin>>t;
    while(t--)
    {
        ll n=sfl(),q=sfl();
        v.resize(n+5,0);
        build(1,1,n);
        printf("Case %d:\n",cases);
        cases++;
        while(q--)
        {
            ll test=sfl();
            if(test==0)
            {
                ll x=sfl(),y=sfl(),v=sfl();
                update(1,1,n,x+1,y+1,v);
            }
            else{
                ll i=sfl(),j=sfl();
                pfl(query(1,1,n,i+1,j+1));
                printf("\n");
            }
        }
        v.clear();
        for(ll i=0;i<4*n;i++)
        {
            tree[i].ff=0;
            tree[i].ss=0;
        }
    }
}
