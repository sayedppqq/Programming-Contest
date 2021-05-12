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
#define  pii    pair< int,int >
#define  pll    pair< ll,ll >
#define  vii    vector< int >
#define  vll    vector< ll >
#define  vpi    vector< pii >
#define  MX     100005
#define  EPS    1e-12
#define  ss     second
#define  ff     first
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
ll dp[305][305];
void it()
{
    for(int i=0;i<=300;i++)
    {
        dp[i][0]=1;
    }
    for(int i=1;i<=300;i++)
    {
        for(int j=1;j<=300;j++)
        {
            if(j>=i)
            {
                dp[i][j]=dp[i-1][j]+dp[i][j-i];
            }
            else
            {
                dp[i][j]=dp[i-1][j];
            }
        }
    }
}
int main()
{
//   freopen ("output.txt","w",stdout);
//   freopen ("input.txt","r",stdin);
//    FIO;
    string s;
    it();
    while(getline(cin,s))
    {
        vii v;
        stringstream ss(s);
        int in;
        while(ss>>in) v.pb(in);
        if(v[0]==0)
        {
            cout<<1<<endl;
            continue;
        }
        if(v.size()==1)
        {
            cout<<dp[v[0]][v[0]]<<endl;
        }
        else if(v.size()==2)
        {
            cout<<dp[v[1]][v[0]]<<endl;
        }
        else
        {
            v[1]--;
            if(v[1]<0) v[1]++;
            cout<<dp[v[2]][v[0]]-dp[v[1]][v[0]]<<endl;
        }
    }
}

