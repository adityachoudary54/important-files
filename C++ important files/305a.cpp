#include<iostream>
using namespace std;
int main()
{
    int n,i,j,k;
    int a[100];
    int b[100];
    cin>>n;
    for(i=0;i<n;i++)
        cin>>a[i];
    j=0;
    k=0;
    for(i=0;i<n;i++)
    {
        if(a[i]==100||a[i]==0)
        {
            b[j++]=a[i];
        }
    }
    for(i=0;i<n;i++)
    {
        if(a[i]<10&&a[i]!=0)
        {
            b[j++]=a[i];
            k=1;
            break;
        }
    }
    for(i=0;i<n;i++)
    {
        if((a[i]>=10)&&(a[i]%10==0)&&(a[i]!=100))
        {
            b[j++]=a[i];
            k=1;
            break;
        }
    }
    if(!k)
    {
        for(i=0;i<n;i++)
        {
            if((a[i]>10)&&(a[i]%10!=0))
            {
                b[j++]=a[i];
                break;
            }
        }
    }
    cout<<j<<endl;
   for(i=0;i<j;i++)
        cout<<b[i]<<" ";
    return 0;
}
