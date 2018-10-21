#include<iostream>
using namespace std;
void merge(int a[],int left,int mid,int right)
{
    int temp[50],i,j,k;
    i=left;
    j=mid+1;
    k=left;
    while(i<=mid&&j<=right)
    {
        if(a[i]<=a[j])
        {
            temp[k++]=a[i++];
        }
        else
        {
            temp[k++]=a[j++];
        }
    }
    if(i<=mid)
    {
        while(i<=mid)
            temp[k++]=a[i++];
    }
    else if(j<=right)
    {
        while(j<=right)
            temp[k++]=a[j++];
    }
    for(int i=left;i<=right;i++)
        a[i]=temp[i];
}
void merge_sort(int a[],int left,int right)
{
    if((right-left)==0)
        return;
    int mid=(left+right)/2;
    merge_sort(a,left,mid);
    merge_sort(a,mid+1,right);
    merge(a,left,mid,right);
}
int main()
{
    int a[]={5,4,3,2,1};
    int n=sizeof(a)/sizeof(int);
    merge_sort(a,0,n-1);
    for(int k=0;k<n;k++)
        cout<<a[k]<<" ";
    return 0;
}
