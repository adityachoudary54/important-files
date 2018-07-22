#include<iostream>
using namespace std;
int upperbound(int a[],int n,int num)
{
    int s,e,mid,t;
    s=0;
    e=n-1;
    t=-1;
    while(s<=e)
    {
        mid=(s+e)/2;
        if(num>a[mid])
        {
            s=mid+1;
        }
        else if(num<a[mid])
        {
            e=mid-1;
        }
        else
        {
            t=mid;
            s=mid+1;
        }
    }
    return t;
}
int lowerbound(int a[],int n,int num)
{
    int s,e,mid,t;
    s=0;
    e=n-1;
    t=-1;
    while(s<=e)
    {
        mid=(s+e)/2;
        if(num>a[mid])
        {
            s=mid+1;
        }
        else if(num<a[mid])
        {
            e=mid-1;
        }
        else
        {
            t=mid;
            e=mid-1;
        }
    }
    return t;
}
int main()
{
    int a[100],n;
    int num;
    cin>>n>>num;
    for(int i=0;i<n;i++)
        cin>>a[i];
    cout<<upperbound(a,n,num)<<endl;
    cout<<lowerbound(a,n,num)<<endl;
    return 0;
}




















