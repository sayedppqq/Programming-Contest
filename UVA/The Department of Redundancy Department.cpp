#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    map<int,int> m;
    vector<int>v;
    int t;
    while(cin>>t)
    {
        m[t]++;
        v.push_back(t);
    }
    for(int i=0;i<v.size();i++)
    {
        if(m[v[i]]){
        cout<<v[i]<<" "<<m[v[i]]<<endl;
        m[v[i]]=0;
        }
    }
}

