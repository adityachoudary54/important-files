#include<iostream>
using namespace std;
int polynomial(int a[],int x,int n,int i)
{
    if(i==n-1)
    {
        return a[i];
    }
    else
    {
        return a[i] +x*(polynomial(a,x,n,i+1));
    }
}
int main()
{
    int a[100],x,n;
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>a[i];
    cout<<polynomial(a,2,n,0);
    return 0;
}
