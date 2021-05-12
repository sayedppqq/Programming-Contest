#include<stdio.h>
int main()
{
    int test,a,b,c,i;
    freopen("data.txt" , "r" , stdin);
    freopen("ans.txt" , "w" , stdout);
    scanf("%d",&test);
    for (i=1;i<=test;i++){
        scanf("%d%d%d",&a,&b,&c);
    if(((a<b) && (a>c)) || ((a<c) && (a>b))) printf("Case %d: %d\n",i,a);
    if(((b<a) && (b>c)) || ((b<c) && (b>a))) printf("Case %d: %d\n",i,b);
    if(((c<a) && (c>b)) || ((c<b) && (c>a))) printf("Case %d: %d\n",i,c);
    if(a==b && b==c && c==a) printf("Case %d: %d\n",i,a);
    }
    return 0;
}
