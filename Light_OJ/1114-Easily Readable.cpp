#include<bits/stdc++.h>
using namespace std;
#define  FIO        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define  all(v)     v.begin(),v.end()
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
int main()
{
//   freopen ("output.txt","w",stdout);
//   freopen ("input.txt","r",stdin);
    FIO;
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        string s;
        map<string,int>m;
        for(int i=0;i<n;i++)
        {
            cin>>s;
            if(s.size()>2) sort(s.begin()+1,s.end()-1);
            m[s]++;

        }
        int q;
        cin>>q;

        cin.ignore();
        cout<<"Case "<<cases++<<":"<<endl;
        while(q--)
        {
            ll ans=1;
            getline(cin,s);
            stringstream ss(s);
            while(ss>>s){

                if(s.size()>2) sort(s.begin()+1,s.end()-1);
                ans*=m[s];
            }
            cout<<ans<<endl;
        }


    }
}
