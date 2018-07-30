#include<iostream>
using namespace std;
void bubble_sort(int a[],int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(a[j]>a[j+1])
                swap(a[j],a[j+1]);
        }
    }
}
void rec_bubblesort(int a[],int n)
{
    if(n==1)
        return;
    for(int j=0;j<n-1;j++)
    {
        if(a[j]>a[j+1])
            swap(a[j],a[j+1]);
    }
    rec_bubblesort(a,n-1);
}
int main()
{
    int a[]={5,1,3,4,2};
    int n=sizeof(a)/sizeof(int);
    rec_bubblesort(a,n);
    for(int k=0;k<n;k++)
        cout<<a[k]<<" ";
    return 0;
}
