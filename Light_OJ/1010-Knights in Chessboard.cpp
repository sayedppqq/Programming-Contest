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
    int t,tc=0;
    cin>>t;
    while(t--)
    {
        tc++;
        int r,c;
        cin>>r>>c;
        if(r==1)
        {
            cout<<"Case "<<tc<<": "<<c<<endl;
            continue;
        }
        if(c==1)
        {
            cout<<"Case "<<tc<<": "<<r<<endl;
            continue;
        }
        if((r==3 && c==2) || (c==3 && r==2) ||(c==2 && r==2))
        {
            cout<<"Case "<<tc<<": "<<4<<endl;
            continue;
        }
        if(r==2 || c==2)
        {
            int x,ans;
            if(r==2) x=c;
            else x=r;
            if(x%4==0) ans=4*(x/4);
            else if(x%4==1) ans=2+(4*(x/4));
            else if(x%4==2 || x%4==3) ans=4+(4*(x/4));
            cout<<"Case "<<tc<<": "<<ans<<endl;
            continue;
        }
        if(c%2==0)
        {
//            if(r%2==0)
//            {
                cout<<"Case "<<tc<<": "<<(c/2)*r<<endl;
//            else
//            {
//                cout<<((c/2)*r)+(c/2)<<endl;
//            }
        }
        else
        {
            if(r%2==0)
            {
                cout<<"Case "<<tc<<": "<<((c/2)*r)+(r/2)<<endl;

            }
            else
            {
                cout<<"Case "<<tc<<": "<<((c/2)*r)+(r/2)+1<<endl;
            }
        }
    }
}
