#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    cin.ignore();
    map<string,string> m;
    while(t--)
    {
        string str,str2;
        getline(cin,str);
        getline(cin,str2);
        m[str]=str2;
    }
    int k;
    cin>>k;
    cin.ignore();
    while(k--)
    {
        string str;
        getline(cin,str);
        cout<<m[str];
        cout<<endl;
    }
}
