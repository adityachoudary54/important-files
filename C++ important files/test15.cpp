#include<iostream>
using namespace std;
int main()
{
    int a[]={1,4,2,6,8,9};
    int n=sizeof(a)/sizeof(a[0]);
    for(int i=0;i<n-1;i++)
    {
        swap(a[i],a[i+1]);
    }
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    return 0;
}
