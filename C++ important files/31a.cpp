#include<iostream>
using namespace std;
int main()
{
    int i,j,k,a[1000],n,l;
    cin>>n;
    l=1;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            for(k=0;k<n;k++)
            {
                if((a[i]==a[j]+a[k])&&((i!=j)&&(j!=k)&&(k!=i)))
                {
                    cout<<i+1<<" "<<j+1<<" "<<k+1;
                    return 0;
                }
            }
        }
    }
    if(l)
        cout<<"-1";
    return 0;

}
