#include<iostream>
using namespace std;
void substring(int a[],int n,int i=0)
{
    if(i>=n)
    {
        cout<<endl;
        return;
    }
    for(;i<n;i++)
    {
        cout<<a[i];
        substring(a,n,i+1);
    }
    return ;
}
int main()
{
    int n,a[100];
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>a[i];
    substring(a,n);
    return 0;
}
