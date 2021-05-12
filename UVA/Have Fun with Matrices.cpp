#include <bits/stdc++.h>
using namespace std;

int main()
{
//    ios_base::sync_with_stdio(false);
//    cin.tie(NULL);
//    cout.tie(NULL);
    int t,k=0;
    scanf("%d",&t);
    while(t--)
    {
        k++;
        int n,x=0;
        scanf("%d",&n);
        string s[n];
        int ara[9][9];
        for(int i=0;i<n;i++){
            cin>>s[i];
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                ara[i][j]=s[i][j]-'0';
            }
        }
        int op;
        scanf("%d",&op);
        while(op--)
        {

            string test;
            cin>>test;
            if(test=="row")
            {
                int a,b;
                scanf("%d%d",&a,&b);
                for(int i=0;i<n;i++)
                {
                    swap(ara[a-1][i],ara[b-1][i]);
                }
            }
            else if(test=="col")
            {
                int a,b;
                scanf("%d%d",&a,&b);
                for(int i=0;i<n;i++)
                {
                    swap(ara[i][a-1],ara[i][b-1]);
                }
            }
            else if(test=="inc")
            {
               for(int i=0;i<n;i++)
                {
                    for(int j=0;j<n;j++)
                    {
                        ara[i][j]++;
                        if(ara[i][j]==10)
                            ara[i][j]=0;
                    }
                }
            }
            else if(test=="dec")
            {
                for(int i=0;i<n;i++)
                {
                    for(int j=0;j<n;j++)
                    {
                        ara[i][j]--;
                        if(ara[i][j]==-1)
                            ara[i][j]=9;
                    }
                }
            }
            else if(test=="transpose")
            {

                int extra[9][9];
                for(int i=0;i<n;i++)
                {
                    for(int j=0;j<n;j++)
                    {
                        extra[j][i]=ara[i][j];
                    }
                }
                for(int i=0;i<n;i++)
                {
                    for(int j=0;j<n;j++)
                        ara[i][j]=extra[i][j];
                }
            }
        }
        printf("Case #%d\n",k);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++)
            {
                printf("%d",ara[i][j]);
            }
            printf("\n");
        }
        printf("\n");
    }
}
