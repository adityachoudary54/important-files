#include<iostream>
using namespace std;
void insertion_sort(int a[],int n)
{
    int hole;
    int value;
    for(int i=1;i<n;i++)
    {
        hole=i;
        value=a[i];
        while(hole>0&&(value<a[hole-1]))//remember this step
        {
            a[hole]=a[hole-1];
            hole=hole-1;
        }
        a[hole]=value;
    }
}
void rec_insertionsort(int a[],int n)
{
    if(n==1)
        return ;
    rec_insertionsort(a,n-1);
    int i,last;
    last=a[n-1];
    i=n-2;
    while(i>=0&&(last<a[i]))
    {
        a[i+1]=a[i];
        i--;
    }
    a[i+1]=last;
}
int main()
{
    int a[]={5,1,3,4,2};
    int n=sizeof(a)/sizeof(int);
    rec_insertionsort(a,n);
    for(int k=0;k<n;k++)
        cout<<a[k]<<" ";
    return 0;
}
