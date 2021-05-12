#include<bits/stdc++.h>
using namespace std;
#define  Fileio     freopen("output.txt","w",stdout);freopen("input.txt","r",stdin);
#define  FIO        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
///ref : https://www.youtube.com/watch?v=03I46RVWBd8
///complexity : ///complexity : O(q*block_size + total_block*n) or O((q+n)*sqrt(n))
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
int ara[1000005],K,cases=1,ans[1000005],q,n,occ[1000008],tot;
struct Query
{
    int L,R,idx;
    bool operator < (const Query &other) const {
        int block_own=L/K;
        int block_other=other.L/K;

        if(block_other==block_own) return R<other.R;
        else return block_own<block_other;
    }
}query[1000005];

void add(int idx)
{
    occ[ara[idx]]++;
    if(occ[ara[idx]]==1) tot++;
}
void remove(int idx)
{
    occ[ara[idx]]--;
    if(occ[ara[idx]]==0) tot--;
}
void MO()
{
    sort(query,query+q);
    int L=0,R=-1;
    for(int i=0;i<q;i++)
    {
        //tot=0;
        //debug(query[i].L,query[i].R);
        while(R<query[i].R) add(++R);
        while(L<query[i].L) remove(L++);
        while(R>query[i].R) remove(R--);
        while(L>query[i].L) add(--L);
        ans[query[i].idx]=tot;
    }
}
int main()
{
    //Fileio;
    FIO;
    int t;
    cin>>t;
    while(t--){
        for(int i=1;i<=1000005;i++)
        {
            occ[i]=0;ans[i]=0;
            query[i].idx=0;
            query[i].L=0;
            query[i].R=0;
        }
        cin>>n>>q;
        K=sqrt(n);
        for(int i=0;i<n;i++) cin>>ara[i];

        for(int i=0;i<q;i++)
        {
            cin>>query[i].L>>query[i].R;
            query[i].L--;
            query[i].R--;
            query[i].idx=i;
        }

        MO();
        cout<<"Case "<<cases++<<":\n";
        for(int i=0;i<q;i++) cout<<ans[i]<<"\n";
    }
}
