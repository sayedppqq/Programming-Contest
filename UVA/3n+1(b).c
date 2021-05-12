#include<stdio.h>
int main()
{
    int a,b,i,j,k,n,c,big;
    //freopen("data.txt" , "r" , stdin);
    //freopen("ans.txt" , "w" , stdout);
    while(scanf("%d%d",&a,&b)==2)
    {
            big=0;
            i=a;
            j=b;
            if(a>b) {i=b; j=a;}
            for(k=i;k<=j;k++)
            {
                n=k;
                c=1;
                while(n!=1)
                {
                    if(n%2==0)
                    {
                        n=n/2;
                        c++;
                    }
                    else
                    {
                        n=(3*n)+1;
                        c++;
                    }
                }
                if(big<c) big=c;
            }
            printf("%d %d %d\n",a,b,big);
    }
    return 0;
}
