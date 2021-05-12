#include<bits/stdc++.h>
using namespace std;
#define  FIO        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define  all(v)     v.begin(),v.end()
#define  CLR(a)     memset(a,0,sizeof(a))
#define  SET(a)     memset(a,-1,sizeof(a))
#define pi      acos(-1.0)
#define  bug    cout<<"debug"<<endl;
#define  ll     long long
#define  pb     push_back
#define  pii    pair< int,int >
#define  pll    pair< ll,ll >
#define  vii    vector< int >
#define  vll    vector< ll >
#define  vpi    vector< pii >
#define  MX     100005
#define  INF    10000000000000000
#define  EPS    1e-12
#define  ss     second
#define  ff     first
int dx[]={ -2, -2, -1, 1, 2, 2, 1, -1 };
int dy[]={ -1, 1, 2, 2, 1, -1, -2, -2 };
int visited[10][10],dis[10][10];
string s,e;
bool valid(int x,int y)
{
    if(x>=0 && x<8 && y>=0 && y<8 && visited[x][y]==0)
        return true;
    return false;
}
void bfs()
{
    CLR(visited);
    CLR(dis);
    int a=s[0]-'a';
    int b=s[1]-'0'-1;
    visited[a][b]=1;
    queue<pii> q;
    q.push(make_pair(a,b));
    while(!q.empty())
    {
        pii unboxed=q.front();
        q.pop();
        for(int i=0;i<8;i++)
        {
            int nx=unboxed.ff+dx[i];
            int ny=unboxed.ss+dy[i];
            if(valid(nx,ny))
            {
                dis[nx][ny]=dis[unboxed.ff][unboxed.ss]+1;
                visited[nx][ny]=1;
                q.push(make_pair(nx,ny));
            }
        }
    }
}
int main()
{
    FIO;
    while(cin>>s>>e){
    bfs();
    cout<<"To get from "<<s<<" to "<<e<<" takes "<<dis[e[0]-'a'][e[1]-'0'-1]<<" knight moves.\n";
    }
}
