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
char str[100005];
int n,ans;
class info
{
public:
    int zero=0,one=0,invert=0;
    bool marked=true;
};
info seg[4*MX];
void push(int node)
{
    if(seg[node].marked)
    {
        seg[2*node].invert+=seg[node].invert;
        seg[2*node+1].invert+=seg[node].invert;

        seg[2*node].marked=true;
        seg[2*node+1].marked=true;
        seg[node].marked=false;

        seg[node].invert=0;
    }
}
void build(int node,int s,int e)
{
    if(s==e)
    {
        if(str[s-1]=='1')
            seg[node].one=1;
        else seg[node].zero=1;
        seg[node].invert=0;
    }
    else
    {
        int mid=(s+e)/2;
        build(2*node,s,mid);
        build(2*node+1,mid+1,e);

        seg[node].one=seg[2*node].one+seg[2*node+1].one;
        seg[node].zero=seg[2*node].zero+seg[2*node+1].zero;
        seg[node].invert=0;
    }
}
void update(int node,int s,int e,int lft,int rgt)
{
    if(lft>e || rgt<s) return;
    if(lft<=s && e<=rgt)
    {
        seg[node].invert++;
        seg[node].marked=true;
        return;
    }
    push(node);
    int mid=(s+e)/2;

    update(2*node,s,mid,lft,rgt);
    update(2*node+1,mid+1,e,lft,rgt);
}
void query(int node,int s,int e,int pos)
{
    if(s==e)
    {
        if(seg[node].invert%2)
        {
            if(seg[node].one==0) ans=1;
            else ans=0;
        }
        else
        {
            if(seg[node].one==0) ans=0;
            else ans=1;
        }
    }
    else
    {
        push(node);
        int mid=(s+e)/2;

        if(pos<=mid) query(2*node,s,mid,pos);
        else query(2*node+1,mid+1,e,pos);
    }
}
char que[2];
int main()
{
    //FIO;
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%s",str);
        n=strlen(str);
        build(1,1,n);

        int q;
        scanf("%d",&q);
        printf("Case %d:\n",cases++);
        while(q--)
        {
            scanf("%s", que);
            if(que[0] == 'I')
            {
                int x,y;
                scanf("%d%d",&x,&y);
                update(1,1,n,x,y);
            }
            else
            {
                ans=0;
                int pos;
                scanf("%d",&pos);
                query(1,1,n,pos);
                printf("%d\n",ans);
            }
        }

        MEM(seg,0);
    }
















}
