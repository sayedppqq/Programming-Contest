#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define  FIO        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define  all(v)     v.begin(),v.end()
#define  rall(v)    v.rbegin(),v.rend()
#define  MEM(a,x)   memset(a,x,sizeof(a))
#define  bug        cout<<"bug"<<endl;
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
#define  MX     100005
#define  EPS    1e-12
#define  ss     second
#define  ff     first
using namespace std;
using namespace __gnu_pbds;

template<typename T>
using ordered_set=tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
template<typename T>
using ordered_multiset=tree<T, null_type, less_equal<T>, rb_tree_tag,tree_order_statistics_node_update>;

void Fileio(){freopen ("output.txt","w",stdout);freopen ("input.txt","r",stdin);}
inline ll powr(int n,int o){ll a=1;for(int i=0;i<o;i++)a*=n;return a;}
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
const ll mod=1000000007;
ll seg[4*MX],ans;

bool cmp(const pii&a,const pii&b)
{
    if(a.ff<b.ff) return true;
    else if(a.ff==b.ff)
    {
        if(a.ss>b.ss) return true;
        else return false;
    }
    else return false;
}

void update(int node,int s,int e,int pos,int val)
{
    if(s==e)
    {
        seg[node]=val;
        return;
    }
    int mid=(s+e)/2;

    if(pos<=mid)
        update(2*node,s,mid,pos,val);

    else
        update(2*node+1,mid+1,e,pos,val);

    seg[node]=seg[2*node]+seg[2*node+1];
}
void query(int node,int s,int e,int lft,int rgt)
{
    if(lft>e || rgt<s) return;

    if(s>=lft && e<=rgt)
    {
        ans=(ans+seg[node])%mod;
        return;
    }
    int mid=(s+e)/2;

    query(2*node,s,mid,lft,rgt);
    query(2*node+1,mid+1,e,lft,rgt);

}
int main()
{
    FIO;
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vpi v;

        for(int i=0;i<n;i++)
        {
            int x;
            cin>>x;
            v.pb({x,i});
        }

        sort(all(v),cmp);
        ll tot=0;
        for(int i=0;i<n;i++)
        {
            ans=0;

            query(1,1,n,1,v[i].ss);

            tot=(tot+ans+1)%mod;

            update(1,1,n,v[i].ss+1,ans+1);
        }

        MEM(seg,0);

        cout<<"Case "<<cases++<<": "<<tot<<"\n";
    }
















}
