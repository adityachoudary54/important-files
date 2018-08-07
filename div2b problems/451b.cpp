#include<iostream>
using namespace std;
int rev(long long a[],long long i,long long j)
{
    for(int start=i,endi=j;start<=(i+j)/2;start++,endi--)
    {
        swap(a[start],a[endi]);
    }
}
int main()
{
    long long n,a[100000];
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>a[i];
    int l=-1,r=-1;
    for(int i=0;i<n-1;i++)
    {
        if(a[i]>a[i+1]&&l==-1)
            l=i;
        else if(a[i]<a[i+1]&&r==-1&&l!=-1)
            r=i;
    }
    //cout<<l<<r;
    if(l==r&&r==-1)
    {
        cout<<"yes\n1 1";
    }
    else if(r==-1)
    {
        int i;
        rev(a,l,n-1);
        for(i=0;i<n-1;i++)
        {
            if(a[i]>a[i+1])
                break;
        }
        if(i==n-1)
            cout<<"yes\n"<<l+1<<" "<<n;
        else
            cout<<"no";
    }
    else
    {
        int i;
        rev(a,l,r);
        for(i=0;i<n-1;i++)
        {
            if(a[i]>a[i+1])
                break;
        }
        if(i==n-1)
            cout<<"yes\n"<<l+1<<" "<<r+1;
        else
            cout<<"no";
    }
    return 0;
 /*   for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
    cout<<endl;
    rev(a,1,4);
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";*/
}
