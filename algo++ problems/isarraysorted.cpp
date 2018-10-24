#include<iostream>
using namespace std;
int ifSorted(int a[],int start,int endi)
{
    if(start<endi)
    {
        if(a[start]<a[start+1]&&ifSorted(a,start+1,endi))
        {
            return true;
        }
        return false;
    }
    return true;
}
int main()
{
    int a[100],n;
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>a[i];
    cout<<ifSorted(a,0,n-1);
    return 0;
}
