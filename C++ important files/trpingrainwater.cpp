#include<iostream>
using namespace std;
int water(int a[],int n)
{
    int i,j,cnt,totcnt;
    i=0;
    j=0;
    cnt=0;
    totcnt=0;
    while(i<n)
    {
       // cout<<i<<" ";
        if(a[j]>a[i])
        {
            cnt+=(a[j]-a[i]);
        }
        else
        {
            totcnt+=cnt;
           // cout<<totcnt<<endl;
            cnt=0;
            j=i;
        }
        if(i==(n-1)&&j<(n-1))
        {
            j++;
            i=j;
            cnt=0;
        }
        i++;
    }
    return totcnt;
}
// more efficient solution is to precompute left and right bars and store the water as the diff of min of pillars and height of pillar at which water is
//stored.

int main()
{
    int a[]={3,0,0,2,0,4};
    int n;
    n=sizeof(a)/sizeof(int);
    cout<<water(a,n);
    return 0;
}
