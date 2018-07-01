#include<iostream>
using namespace std;
int main()
{
    int i,n,a[100],j;
    j=0;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(i=0;i<n;i++)
    {
        if(a[i]&1)
            j++;
    }
    if(j==1)
    for(i=0;i<n;i++)
    {
        if(a[i]&1)
        cout<<i+1;
    }
    else
        for(i=0;i<n;i++)
    {
        if((a[i]&1)==0)
        cout<<i+1;
    }
    return 0;
}
