#include<iostream>
using namespace std;
int main()
{
    int n,a[100],i,b[32],j,ans,maxi,ans1,ans2;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(i=0;i<32;i++)
        b[i]=0;
    for(i=0;i<n;i++)
    {
        ans=ans^a[i];
    }
    maxi=0;j=0;
    while(ans)
    {
        if(ans&1)
            break;
        j++;
        ans=ans/2;
    }
    maxi=j;
    ans1=ans2=0;
    for(j=0;j<n;j++)
    {
        if(a[j]&(1<<maxi))
            ans1=ans1^a[j];
        else
            ans2=ans2^a[j];
    }
    cout<<ans1<<" "<<ans2;
}
