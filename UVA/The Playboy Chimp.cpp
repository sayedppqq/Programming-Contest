#include<iostream>
using namespace std;
int main()
{
    int n,dlag,flag,mlag,glag,d,e,f,g,i,t,end,begin,mid,key,found,j,k;
    cin>>n;
    int ara[n];
    for(i=0;i<n;i++)
        cin>>ara[i];
    cin>>t;
    int test[t];
    for(i=0;i<t;i++)
        cin>>test[i];
    for(i=0;i<t;i++)
    {
        flag=0;mlag=0;dlag=0;glag=0;
        d=0;e=0;f=0;g=0;j=0;k=0;
        key=test[i];
        begin=0;
        end=n-1;
        found=-1;
        while(begin<=end)
        {
            mid=(begin+end)/2;
            if(ara[mid]==key)
            {
                found=mid;
                break;
            }
            else if(ara[mid]<key) begin=mid+1;
            else if(ara[mid]>key) end=mid-1;
        }
//        cout<<found<<endl;
        if(found==0)
        {
            d=1;
            while(ara[0]==ara[d])
            {
                d++;
                if(d==n)
                {
                    flag=1;
                    break;
                }
            }
            if(flag==1)
            {
                cout<<"X"<<" "<<"X"<<endl;
            }
            else cout<<"X"<<" "<<ara[d]<<endl;
        }
        else if(found==n-1)
        {
            e=n-2;
            while(ara[n-1]==ara[e])
            {
                e--;
                if(e<0)
                {
                    mlag=1;
                    break;
                }
            }
            if(mlag==1)
            {
                cout<<"X"<<" "<<"X"<<endl;
            }
            else cout<<ara[e]<<" "<<"X"<<endl;
        }
        else if(found!=-1)
        {
            f=found-1;
            g=found+1;
            while(ara[found]==ara[f])
            {
                f--;
                if(f<0)
                {
                    glag=1;
                    break;
                }
            }
            while(ara[found]==ara[g])
            {
                g++;
                if(g==n)
                {
                    dlag=1;
                    break;
                }
            }
            if(glag==1 && dlag==1)
            {
                cout<<"X"<<" "<<"X"<<endl;
            }
            else if(glag==1 && dlag==0)
            {
                cout<<"X"<<" "<<ara[g]<<endl;
            }
            else if(glag==0 && dlag==1)
            {
                cout<<ara[f]<<" "<<"X"<<endl;
            }
            else cout<<ara[f]<<" "<<ara[g]<<endl;
        }
        else
        {
        if(key<ara[0])
        {
            cout<<"X"<<" "<<ara[0]<<endl;
        }
        else if(key>ara[n-1])
        {
            cout<<ara[n-1]<<" "<<"X"<<endl;
        }
        else
        {
            j=0;
            k=n-1;
            while(key>ara[j])
            {
                j++;
            }
            while(key<ara[k])
            {
                k--;
            }
            cout<<ara[j-1]<<" "<<ara[k+1]<<endl;
        }
        }
    }
}
