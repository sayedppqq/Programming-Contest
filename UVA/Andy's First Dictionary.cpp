#include <bits/stdc++.h>
using namespace std;

int main()
{
//    ios_base::sync_with_stdio(false);
//    cin.tie(NULL);
//    cout.tie(NULL);
    string s;
    set<string> st;
    bool ok=false;
    while(getline(cin,s))
    {
        string t;
//        cout<<s<<endl;
        for(int i=0;i<s.size();i++)
        {
//            if(s[i]==' ') continue;
//            cout<<s[i]<<" ";
            if(s[i]>='a' && s[i]<='z')
                t+=s[i];
            else if(s[i]>='A' && s[i]<='Z')
                t+=s[i]+32;
            else
            {
               if(s[i]==' ') ok=true;
               st.insert(t);
               t.erase();
            }
        }
        if(t.size()!=0)
        st.insert(t);
//        cout<<t<<endl;

    }
    if(ok)
        st.erase(st.begin());
    for(auto it=st.begin();it!=st.end();it++)
    {
        cout<<*it<<endl;
    }
}
