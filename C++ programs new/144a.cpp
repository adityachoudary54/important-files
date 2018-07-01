#include<iostream>
using namespace std;
struct one
{
    int x,y;
}a;
int main()
{
    int b[100],i,mini,maxi,n;
    cin>>n;
    for(i=0;i<n;i++)
        cin>>b[i];
    a.x=a.y=b[0];
    mini=maxi=0;
    for(i=1;i<n;i++)
    {
        if(b[i]>a.x)
        {
             a.x=b[i];
             maxi=i;
        }
        if(b[i]<=a.y)
        {
             a.y=b[i];
             mini=i;
        }
    }
    mini=n-mini-1;
    if(maxi+mini>=n)
    mini=mini-1;
    cout<<maxi+mini;
}

