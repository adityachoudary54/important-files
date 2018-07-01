#include<iostream>
using namespace std;
int main()
{
    long int y,k,n,i,tru;
    cin>>y>>k>>n;
    tru=0;
    for(i=1;i<n/k;i++)
    {
        if((k*i-y)>0)
        {
            cout<<k*i-y<<" ";
            tru=1;
        }
    }
    if((k*i<=n)&&((k*i-y)>0))
    {
        cout<<k*i-y;
        tru=1;
    }
    if(!tru)
        cout<<"-1";
    return 0;
}
