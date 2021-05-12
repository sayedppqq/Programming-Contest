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
class info
{
public:
    int zero=0,one=0,two=0,added=0;
};
int n,q;
info seg[4*MX];

void push_up(int node)
{
    seg[node].one=seg[2*node].one+seg[2*node+1].one;
    seg[node].two=seg[2*node].two+seg[2*node+1].two;
    seg[node].zero=seg[2*node].zero+seg[2*node+1].zero;
}

void loop(int node)
{
    int o=seg[node].one,t=seg[node].two,z=seg[node].zero;
    seg[node].one=z;
    seg[node].two=o;
    seg[node].zero=t;
}

void push_down(int node)
{
    if(seg[node].added)
    {
        seg[2*node].added+=seg[node].added;
        seg[2*node+1].added+=seg[node].added;

        for(int i=0;i<seg[node].added%3;i++)
        {
            loop(2*node);
            loop(2*node+1);
        }
        seg[node].added=0;
    }
}

void build(int node,int s,int e)
{
    if(s==e)
    {
        seg[node].zero=1;
        seg[node].one=0;
        seg[node].two=0;
        seg[node].added=0;
    }
    else
    {
        int mid=(s+e)/2;
        build(2*node,s,mid);
        build(2*node+1,mid+1,e);
        push_up(node);
    }
}

void update(int node,int s,int e,int lft,int rgt)
{
    if(lft>e || rgt<s) return;
    if(lft<=s && e<=rgt)
    {
        seg[node].added++;
        loop(node);
        return;
    }
    push_down(node);
    int mid=(s+e)/2;
    update(2*node,s,mid,lft,rgt);
    update(2*node+1,mid+1,e,lft,rgt);
    push_up(node);
}

int query(int node,int s,int e,int lft,int rgt)
{
    if(lft>e || rgt<s) return 0;
    if(lft<=s && rgt>=e)
    {
        return seg[node].zero;
    }
    else
    {
        push_down(node);
        int mid=(s+e)/2;
        int a=query(2*node,s,mid,lft,rgt);
        int b=query(2*node+1,mid+1,e,lft,rgt);
        return a+b;
    }
}
int main()
{
    //FIO;
   // Fileio();
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&q);
        build(1,1,n);

        printf("Case %d:\n",cases++);

        while(q--)
        {
            int tt,i,j;
            scanf("%d%d%d",&tt,&i,&j);
            if(tt==0)
            {
                update(1,1,n,i+1,j+1);
            }
            else{
                printf("%d\n",query(1,1,n,i+1,j+1));
            }
        }
        MEM(seg,0);
    }
















}
