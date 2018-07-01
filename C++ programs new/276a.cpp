#include<iostream>
using namespace std;
struct rab
{
    long int f,t;
}a[10000];

int main()
{
    long int i,n,k,maxi;
    cin>>n>>k;
    for(i=0;i<n;i++)
    {
        cin>>a[i].f>>a[i].t;
    }
    for(i=0;i<n;i++)
    {
        if(a[i].t>k)
            a[i].f=a[i].f-(a[i].t-k);
        if(i==0)
        maxi=a[i].f;
        if(a[i].f>maxi)
            maxi=a[i].f;
    }
    cout<<maxi;
}
