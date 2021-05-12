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
#define  MX     200050
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
class info
{
public:
    int val=0;
    bool marked=false;
    info(int a,bool b)
    {
        val=a;
        marked=b;
    }
};
int n;
vector<info> seg;
bool ok[MX];
void push(int node)
{
    if(seg[node].marked)
    {
        seg[2*node].val=seg[node].val;
        seg[2*node].marked=true;
        seg[2*node+1].val=seg[node].val;
        seg[2*node+1].marked=true;

        seg[node].marked=false;
    }
}
void update(int node,int s,int e,int lft,int rgt,int value)
{
    if(lft>e || rgt<s) return;
    if(lft<=s && e<=rgt)
    {
        seg[node].val=value;
        seg[node].marked=true;
        return;
    }
    push(node);
    int mid=(s+e)/2;
    update(2*node,s,mid,lft,rgt,value);
    update(2*node+1,mid+1,e,lft,rgt,value);
}
void query(int node,int s,int e,int lft,int rgt)
{
    if(lft>e || rgt<s) return;
    if(lft<=s && e<=rgt)
    {
        ok[seg[node].val]=true;
        return;
    }
    push(node);
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
        cin>>n;
        seg.assign(4*3*n,info(0,false));
        for(int k=1;k<=n;k++)
        {
            int l,r;
            cin>>l>>r;
            update(1,1,2*n,l,r,k);
        }
        for(int i=1;i<=2*n;i++)
        {
            query(1,1,2*n,i,i);
        }
        int ans=0;
        for(int i=1;i<=n;i++) if(ok[i]) ans++;
        cout<<"Case "<<cases++<<": "<<ans<<"\n";

        for(int i=0;i<MX;i++) ok[i]=false;
        seg.clear();
    }
















}
