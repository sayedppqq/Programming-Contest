#include<bits/stdc++.h>
using namespace std;
#define  FIO        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define  all(v)     v.begin(),v.end()
#define pi     acos(-1.0)
#define  ll     long long
#define  pb     push_back
#define  pii    pair< int,int >
#define  pll    pair< ll,ll >
#define  vii    vector< int >
#define  vll    vector< ll >
#define  vpi    vector< pii >
#define  MX     10000005
#define  INF    10000000000000000
#define  EPS    1e-12
#define  ss     second
#define  ff     first
bool marked[MX+5];
vll primes;
void sieve()
{
    marked[0]=marked[1]=true;
    primes.pb(2);
    for(int i=3; i*i<MX; i+=2)
    {
        if(!marked[i])
        {
            for(int j=i*i; j<=MX; j+=i*2)
                marked[j]=true;
        }
    }
    for(int i=3; i<=MX; i+=2)
    {
        if(!marked[i])
            primes.pb(i);
    }
}
int main()
{
    FIO;
    sieve();
    int t;
    cin>>t;
    int k=0;
    while(t--)
    {
        k++;
        ll a;
        cin>>a;
        int divisor=1;
        for(int i=0;primes[i]*primes[i]<=a;i++)
        {
            if(a%primes[i]==0)
            {
                int count=1;
                while(a%primes[i]==0)
                {
                    a/=primes[i];
                    count++;
                }
                divisor*=count;
            }

        }
        if(a>1) divisor*=2;
        cout<<"Case "<<k<<": "<<divisor-1<<endl;
    }
}
