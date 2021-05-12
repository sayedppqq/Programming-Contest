#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define  FIO        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define  all(v)     v.begin(),v.end()
#define  rall(v)    v.rbegin(),v.rend()
#define  MEM(a,x)   memset(a,x,sizeof(a))
#define  SZ(v)      v.size()
#define  nl         "\n"
#define  bug        cout<<"bug"<<nl;
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
inline ll powr(int a,int b){ll res=1;while(b){if(b&1) res*=a;a*=a;b/=2;}return res;}
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
string s[9];
vpi ini_pos,temp,temp2;
int paisi[4],vis[10][10],ro,col;
queue<vpi> q;
map<pii,int> m;
set<vpi> st;

void init()
{
    MEM(paisi,0);
    ini_pos.assign(4,{0,0});
}
void lastCLR()
{
    st.clear();
    m.clear();
}

bool up_sort(const pii& a,const pii& b)
{
    if(a.ff<b.ff) return true;
    else return false;
}
bool down_sort(const pii& a,const pii& b)
{
    if(a.ff>b.ff) return true;
    else return false;
}
bool left_sort(const pii& a,const pii& b)
{
    if(a.ss<b.ss) return true;
    else return false;
}
bool right_sort(const pii& a,const pii& b)
{
    if(a.ss>b.ss) return true;
    else return false;
}

bool validRIGHT()
{
    if(col==6 || vis[ro][col+2] || vis[ro+1][col+2] || s[ro][col+2]=='#' || s[ro+1][col+2]=='#')
        return false;
    else return true;
}
void go_right()
{
    for(int i=0;i<4;i++)
    {
        ro=temp[i].ff;
        col=temp[i].ss;
        while(true)
        {
            if(!validRIGHT()) break;
            else
            {
                col++;
            }
        }
        vis[ro][col]=1;
        vis[ro+1][col]=1;
        temp2[m[temp[i]]].ff=ro;
        temp2[m[temp[i]]].ss=col;
    }
    if(st.find(temp2)==st.end())
    {
        st.insert(temp2);
        q.push(temp2);
    }
}


bool validLEFT()
{
    if(col-1<0 || vis[ro][col-1] || vis[ro+1][col-1] || s[ro][col-1]=='#' || s[ro+1][col-1]=='#')
        return false;
    else return true;
}
void go_left()
{
    for(int i=0;i<4;i++)
    {
        ro=temp[i].ff;
        col=temp[i].ss;
        while(true)
        {
            if(!validLEFT()) break;
            else
            {
                col--;
            }
        }
        vis[ro][col+1]=1;
        vis[ro+1][col+1]=1;
        temp2[m[temp[i]]].ff=ro;
        temp2[m[temp[i]]].ss=col;
    }
    if(st.find(temp2)==st.end())
    {
        st.insert(temp2);
        q.push(temp2);
    }
}


bool validDOWN()
{
    if(ro+1==7 || vis[ro+2][col] || vis[ro+2][col+1] || s[ro+2][col]=='#' || s[ro+2][col+1]=='#')
        return false;
    else return true;
}
void go_down()
{
    for(int i=0;i<4;i++)
    {
        ro=temp[i].ff;
        col=temp[i].ss;
        while(true)
        {
            if(!validDOWN()) break;
            else
            {
                ro++;
            }
        }
        vis[ro][col]=1;
        vis[ro][col+1]=1;
        temp2[m[temp[i]]].ff=ro;
        temp2[m[temp[i]]].ss=col;
    }
    if(st.find(temp2)==st.end())
    {
        st.insert(temp2);
        q.push(temp2);
    }
}


bool validUP()
{
    if(ro-1<0 || vis[ro-1][col] || vis[ro-1][col+1] || s[ro-1][col]=='#' || s[ro-1][col+1]=='#')
        return false;
    else return true;
}
void go_up()
{
    for(int i=0;i<4;i++)
    {
        ro=temp[i].ff;
        col=temp[i].ss;
        while(true)
        {
            if(!validUP()) break;
            else
            {
                ro--;
            }
        }
        vis[ro+1][col]=1;
        vis[ro+1][col+1]=1;
        temp2[m[temp[i]]].ff=ro;
        temp2[m[temp[i]]].ss=col;
    }
    if(st.find(temp2)==st.end())
    {
        st.insert(temp2);
        q.push(temp2);
    }
}



void bfs()
{
    temp=ini_pos;
    q.push(temp);


    while(!q.empty())
    {
        vpi cur=q.front();
        q.pop();
        for(int i=0;i<4;i++) m[cur[i]]=i;

        temp2=cur;
        MEM(vis,0);
        temp=cur;
        sort(all(temp),up_sort);
        go_up();

        temp2=cur;
        MEM(vis,0);
        temp=cur;
        sort(all(temp),down_sort);
        go_down();

        temp2=cur;
        MEM(vis,0);
        temp=cur;
        sort(all(temp),left_sort);
        go_left();

        temp2=cur;
        MEM(vis,0);
        temp=cur;
        sort(all(temp),right_sort);
        go_right();
    }
}


int main()
{
    FIO;
    //Fileio();
    int t;
    cin>>t;

    while(t--)
    {
        init();
        for(int i=0;i<8;i++) cin>>s[i];

        for(int i=0;i<8;i++)
        {
            for(int j=0;j<8;j++)
            {
                if(s[i][j]!='#' && s[i][j]!='.' && paisi[s[i][j]-'A']==0)
                {
                    ini_pos[s[i][j]-'A'].ff=i;
                    ini_pos[s[i][j]-'A'].ss=j;
                    paisi[s[i][j]-'A']=1;
                }
            }
        }

        bfs();

        cout<<"Case "<<cases++<<":"<<" "<<SZ(st)<<nl;

        lastCLR();

    }
}
