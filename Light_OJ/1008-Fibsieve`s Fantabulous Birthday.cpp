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
#define  MX     100005
#define  EPS    1e-12
#define  ss     second
#define  ff     first

int dx[]={ -2, -2, -1, 1, 2, 2, 1, -1 };
int dy[]={ -1, 1, 2, 2, 1, -1, -2, -2 };
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

int main()
{
//   freopen ("output.txt","w",stdout);
//   freopen ("input.txt","r",stdin);
    FIO;
    int t;
    cin>>t;
    int tc=0;
    while(t--)
    {
        tc++;
        ll n,box;
        cin>>n;
        long double sq=sqrt(n);
        ll check=sqrt(n);
        if(sq-check>0.0) box=check+1;
        else box=check;
        ll mid=(box-1)*(box-1)+box;
        debug(mid,box);
        if(box%2==0){
        if(n>mid)
        {
            cout<<"Case "<<tc<<": "<<box<<" "<<((box*box)-n)+1<<endl;
        }
        else
        {
            cout<<"Case "<<tc<<": "<<n-((box-1)*(box-1)+1)+1<<" "<<box<<endl;
        }
        }

        else
        {
            if(n>mid)
        {
            cout<<"Case "<<tc<<": "<<((box*box)-n)+1<<" "<<box<<endl;
        }
        else
        {
            cout<<"Case "<<tc<<": "<<box<<" "<<n-((box-1)*(box-1)+1)+1<<endl;
        }
        }
    }
}
