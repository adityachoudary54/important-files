#include<iostream>
using namespace std;
int partition(int a[],int start,int endi)
{
    int i,pindex,t;
    pindex=i=start;
    t=a[endi];
    while(i<=endi-1)
    {
        if(a[i]<=t)
        {
            swap(a[i],a[pindex]);
            pindex++;
        }
        i++;
    }
    swap(a[pindex],a[endi]);
    return pindex;
}
void quick_sort(int a[],int start,int endi)
{
    if(start<endi)
    {
        int pivot=partition(a,start,endi);
        quick_sort(a,start,pivot-1);
        quick_sort(a,pivot+1,endi);
    }
}
int main()
{
    int a[]={5,1,3,4,2};
    int n=sizeof(a)/sizeof(int);
    quick_sort(a,0,n-1);
    for(int k=0;k<n;k++)
        cout<<a[k]<<" ";
    return 0;
}

