#include<iostream>
using namespace std;
int main()
{
    int i,n,a[100];
    cin>>n;
    if(n&1)
    {
        cout<<-1;
        return 0;
    }
    for(i=0;i<n;i++)
    {
        a[i]=i+1;
    }
    for(i=0;i<n;i=i+2)
    {
        swap(a[i],a[i+1]);
    }
    for(i=0;i<n;i++)
        cout<<a[i]<<" ";
    return 0;
}
