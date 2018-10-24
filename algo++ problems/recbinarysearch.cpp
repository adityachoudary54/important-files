#include<iostream>
using namespace std;
int binarysearch(int a[],int x,int start,int endi)
{
    if(start<endi)
    {
        int mid=(start+endi)/2;
        if(a[mid]==x)
            return mid;
        else if(a[mid]>x)
            return binarysearch(a,x,start,mid-1);
        else
            return binarysearch(a,x,mid+1,endi);
    }
    return -1;
}
int main()
{
    int a[100],n,x;
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>a[i];
    cin>>x;
    cout<<binarysearch(a,x,0,n-1);

}
