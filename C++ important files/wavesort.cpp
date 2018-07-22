#include<iostream>
#include<algorithm>
using namespace std;
void wavesort(int a[],int n)
{
    int i;
    for(i=0;i<n;i+=2)
    {
        if(a[i]<a[i+1])
           swap(a[i],a[i+1]);
        if(a[i]<a[i-1]&&i!=0)
            swap(a[i],a[i-1]);
    }
}
int main()
{

    int t,i,j;
    int a[131][1000];
    int n[131];
    cin>>t;
    for(i=0;i<t;i++)
    {   cin>>n[i];
        for(j=0;j<n[i];j++)
            cin>>a[i][j];
    }
    for(i=0;i<t;i++)
        wavesort(a[i],n[i]);
    for(i=0;i<t;i++)
    {
        for(j=0;j<n[i];j++)
        cout<<a[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}
