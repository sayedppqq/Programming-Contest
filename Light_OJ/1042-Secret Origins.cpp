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
int main()
{
//   freopen ("output.txt","w",stdout);
//   freopen ("input.txt","r",stdin);
//    FIO;
    ll t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        ll m=n;
        string bn;
        if(m%2!=0) bn+='1';
        else bn+='0';
        while(m/2!=0)
        {
            m=m/2;
            if(m%2!=0) bn+='1';
            else bn+='0';
        }
        reverse(bn.begin(), bn.end());
        string nw="0";
        nw+=bn;
        int sz=nw.size();
        int one=0;
        for(int i=sz-1;i>0;i--)
        {
            if(nw[i]=='1') one++;
            if(nw[i]=='1' && nw[i-1]=='0')
            {
                one--;
                swap(nw[i],nw[i-1]);
                int h=one;
                for(int j=sz-1;j>i && h;j--)
                {
                    nw[j]='1';
                    h--;
                }

                break;
            }
            else nw[i]='0';

        }
        string ans;
        ans=nw;
        ll val=0,k=0;
        for(int i=ans.size()-1;i>=0;i--)
        {
            val+=((ans[i]-'0')*pow(2,k));
            k++;

        }
        cout<<"Case "<<cases<<": "<<val<<endl;
        cases++;
    }
}
