#include<iostream>
using namespace std;
int linearsearch(int a[],int x,int n)
{
    if(n==0)
        return -1;
    if(a[n-1]==x)
        return n-1;
    return linearsearch(a,x,n-1);
}
int main()
{
    int a[100],n,x;
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>a[i];
    cin>>x;
    cout<<linearsearch(a,x,n);
}
