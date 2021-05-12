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
struct node
{
    bool endpoint;
    int teq=0;
    node *next[4];
    node()
    {
        endpoint=false;
        for(int i=0;i<4;i++)
        {
            next[i]=NULL;
        }
    }
};
node *root;
int maxi;
void insert ( string s )
{
    node *cur=root;
    for(int i=0;i<s.size();i++)
    {
        int id;
        if(s[i]=='A') id=0;
        else if(s[i]=='C') id=1;
        else if(s[i]=='T') id=2;
        else if(s[i]=='G') id=3;
        if(cur->next[id] == NULL)
            cur->next[id] = new node();
        cur=cur->next[id];
        cur->teq++;
        maxi=max(maxi,cur->teq*(i+1));
    }
    cur->endpoint=true;
}
int ara[100];
bool search ( string s )
{
    node *cur = root;
    for(int i=0;i<s.size();i++)
    {
        int id=s[i]-'a';
        if(cur->next[id] == NULL)
            return false;
        cur=cur->next[id];
    }
    return cur->endpoint;
}
void del ( node *cur )
{
    for(int i=0;i<4;i++)
    {
        if(cur->next[i])
            del(cur->next[i]);
    }
    delete ( cur );
}
int main()
{
   //freopen ("output.txt","w",stdout);
   //freopen ("input.txt","r",stdin);
    FIO;

    int t;
    cin>>t;
    while(t--)
    {
        root = new node();
        maxi=0;
        int n;
        cin>>n;
        vector<string> v(n);
        for(int i=0;i<n;i++)
        {
            cin>>v[i];
        }
        sort(all(v));
        for(int i=0;i<n;i++)
        {
            insert(v[i]);
        }
        cout<<"Case "<<cases++<<": ";
        cout<<maxi<<endl;
        del(root);
    }
}

