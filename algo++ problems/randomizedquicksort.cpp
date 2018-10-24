#include<iostream>
#include<ctime>
#include<cstdlib>
using namespace std;

void shuffle(int *a,int n)
{
    srand(time(NULL));
    int i,j,temp;
    for(int i=n-1;i>0;i--)
    {
        //Create one random index
        j=rand()%(i+1);
        swap(a[j],a[i]);
    }
}

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
    for(int k=0;k<=(endi-start);k++)
    {
        cout<<a[k]<<" ";
    }
    cout<<start<<" "<<endi<<endl;
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
    int a[]={1,2,5,4,3};
    int n=sizeof(a)/sizeof(int);
    shuffle(a,n);
    quick_sort(a,0,n-1);
    for(int k=0;k<n;k++)
        cout<<a[k]<<" ";
    return 0;
}


