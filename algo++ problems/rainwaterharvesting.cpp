#include<iostream>
using namespace std;
int main()
{
    int n,a[100000],collected_water[100],left[100000],right[100000],t;
    t=1;
    for(int k=0;k<t;k++)
    {
        collected_water[k]=0;
        cin>>n;
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
        left[0]=a[0];
        for(int i=1;i<n;i++)
        {
            if(left[i-1]>a[i])
                left[i]=left[i-1];
            else
                left[i]=a[i];
        }
        right[n-1]=a[n-1];
        for(int i=n-2;i>=0;i--)
        {
            if(right[i+1]>a[i])
                right[i]=right[i+1];
            else
                right[i]=a[i];
        }
        for(int i=0;i<n;i++)
        {
            collected_water[k]+=(min(left[i],right[i])-a[i]);
        }
    }
    for(int i=0;i<t;i++)
    {
        cout<<collected_water[i];
    }
    return 0;
}
