#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    while(cin>>n)
    {
        if(n==0) break;
        int ara[101][101],durniti=0,pick1,pick2;
        for(int i=0;i<n;i++)
        {
            int count=0;
            for(int j=0;j<n;j++)
            {
                scanf("%d",&ara[i][j]);
                if(ara[i][j]==1)
                    count++;
            }
            if(count%2!=0)
            {
                durniti++;
                if(durniti==1)
                    pick1=i;
            }
        }
        if(durniti>1)
        {
            printf("Corrupt\n");
            continue;
        }
        int ok=0;
        for(int i=0;i<n;i++)
        {
            int col=0;
            for(int j=0;j<n;j++)
            {
                if(ara[j][i]==1) col++;
            }
            if(col%2!=0)
            {
                ok++;
                if(ok>1)
                    break;
                else pick2=i;
            }
        }
        if(ok>1)
        {
            printf("Corrupt\n");
            continue;
        }
        if(durniti==1 && ok==1)
            printf("Change bit (%d,%d)\n",pick1+1,pick2+1);
        else if(durniti==0 && ok==0)
            printf("OK\n");
    }
}
