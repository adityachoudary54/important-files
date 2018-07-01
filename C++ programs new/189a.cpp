#include<iostream>
using namespace std;
int main()
{
    int n,i,j,k,sum,a[3],t,p[3];
    cin>>n>>a[0]>>a[1]>>a[2];
    sum=0;
    for(i=0;i<=n;i++)
    {
        for(j=0;j<=n;j++)
        {
            if(((((n-a[0]*i-a[1]*j)%a[2])==0)&&((n-a[0]*i-a[1]*j)>0))||((n-a[0]*i-a[1]*j)==0))
            {
                   k=(n-a[0]*i-a[1]*j)/a[2];
                   if(sum<(i+j+k))
                    {
                        sum=i+j+k;
                    }
            }
        }
    }
    cout<<sum;
}
