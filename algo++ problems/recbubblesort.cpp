#include<iostream>
using namespace std;
void rec_bubble_sort(int a[],int j,int n)
{
    if(n==1)
    {
        return ;
    }
    if(j==n-1)
    {
        return rec_bubble_sort(a,0,n-1);
    }
    if(a[j]>a[j+1])
        swap(a[j],a[j+1]);
    rec_bubble_sort(a,j+1,n);
    return;
}
int main()
{
    int a[]={5,1,3,4,2};
    int n=sizeof(a)/sizeof(int);
    rec_bubble_sort(a,0,n);
    for(int k=0;k<n;k++)
        cout<<a[k]<<" ";
    return 0;

}
