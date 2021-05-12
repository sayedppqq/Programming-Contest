#include<stdio.h>
int main()
{
    int p,i,x,y,m,n,test;
    for(p=1;;p++)
    {
        scanf("%d",&test);
        if (test==0) break;
        scanf("%d%d",&m,&n);
        for(i=1;i<=test;i++)
        {
            scanf("%d%d",&x,&y);
            if(x>m && y>n) printf("NE\n");
            if(x<m && y>n) printf("NO\n");
            if(x>m && y<n) printf("SE\n");
            if(x<m && y<n) printf("SO\n");
            if(x==m || y==n) printf("divisa\n");
        }
    }
    return 0;
}
