#include<iostream>
using namespace std;
int maxbitonicsubarray(int a[],int n)
{
    int inc[1000],dec[1000];
    inc[0]=dec[n-1]=1;
    for(int i=1;i<n;i++)
    {
        if(a[i]>a[i-1])
            inc[i]=1+inc[i-1];
        else
            inc[i]=1;
    }
    for(int i=n-2;i>=0;i--)
    {
        if(a[i]>a[i+1])
            dec[i]=1+dec[i+1];
        else
            dec[i]=1;
    }
    int max=0;
//    for(int i=0;i<n;i++)
//    {
//        cout<<inc[i]<<" ";
//    }
//    cout<<endl;
//    for(int i=0;i<n;i++)
//    {
//        cout<<dec[i]<<" ";
//    }
//    cout<<endl;
    for(int i=0;i<n;i++)
    {
        if(max<(dec[i]+inc[i]-1))
            max=dec[i]+inc[i]-1;
    }

    return max;
}
int main()
{
    int a[1000],n,t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        cin>>n;
        for(int k=0;k<n;k++)
        {
            cin>>a[k];
        }
        cout<<maxbitonicsubarray(a,n)<<endl;
    }
    return 0;
}
