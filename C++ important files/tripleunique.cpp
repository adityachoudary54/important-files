#include<iostream>
using namespace std;
int main()
{
    int n,a[100],i,b[32],j,ans;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(i=0;i<32;i++)
        b[i]=0;
    for(i=0;i<n;i++)
    {
        j=0;
        while(a[i])
        {
            //cout<<b[j]<<" "<<j<<endl;
            if(a[i]&1)
                b[j]++;
            j++;
            a[i]=a[i]/2;
        }

    }
    ans=0;
    for(i=0;i<3;i++)
    {
        b[i]=b[i]%3;
        ans=ans+(b[i]<<i);
    }
    cout<<ans;
    return 0;
}
