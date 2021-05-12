#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
    stack<char> s1;
    string s;
    cin>>s;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='(' || s[i]=='['){
            s1.push(s[i]);
            }
        else if(s[i]==']')
        {
            if(s1.empty() || s1.top()!='[')
                {s1.push('a');
					break;}
            else
            {
                s1.pop();
            }
        }
        else if(s[i]==')')
        {
            if(s1.empty() || s1.top()!='(')
                {s1.push('a');
					break;}
            else
            {
              s1.pop();
            }
        }
    }
    if(s1.empty()) cout<<"Yes\n";
    else cout<<"No\n";
    }
    return 0;
}
