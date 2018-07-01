#include<iostream>
using namespace std;
int partition(int a[],int start,int endi)
{
    int pivot,i,t,pi;
    i=start;
    pivot=start;
    pi=a[endi];
    while(i<=endi-1)
    {
        if(a[i]<=pi)
        {
           t=a[i];
           a[i]=a[pivot];
           a[pivot]=t;
            pivot++;
        }
        i++;
    }
    t=a[endi];
    a[endi]=a[pivot];
    a[pivot]=t;
    return pivot;
}

int quicksort(int arr[],int start,int endi)
{
    int pivot;
    if(start<endi)
    {
        pivot=partition(arr,start,endi);
        quicksort(arr,0,pivot-1);
        quicksort(arr,pivot+1,endi);
    }
    return 0;
}



int main()
{
    int i,n,a[100],sumarr,sumtwin,k;
    sumarr=k=sumtwin=0;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
        sumarr+=a[i];
    }
    quicksort(a,0,n-1);
    while((sumarr-sumtwin)>=sumtwin)
    {
        sumtwin+=a[n-k-1];
        k++;
    }
    cout<<k;

}














