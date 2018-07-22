#include<iostream>
using namespace std;
int min_sum(int a[],int arr_size,int num_stud)
{
    int s,e,mid,b[20];
    //mid=total_sum/3;
    s=0;
    e=0;
    int i,j;
    for(i=0;i<arr_size;i++)
    {
        e+=a[i];
    }
    while(s<=e)
    {
        mid=(s+e)/2;
        cout<<mid<<endl;
        for(i=0;i<num_stud;i++)
        {
            b[i]=0;
        }
        i=0;j=0;
        while(j<=arr_size-1)
        {
            if(i==(num_stud-1))
            {
                b[i]=b[i]+a[j];
               // cout<<"1 "<<b[i]<<endl;
                j++;
            }
            else if(b[i]<mid)
            {
                b[i]=b[i]+a[j];
                //cout<<"2 "<<b[i]<<endl;
                j++;
            }
            else if(b[i]==mid)
            {
                i++;
            }
            else
            {
                b[i]-=a[j-1];
                //cout<<"3 "<<b[i]<<endl;
                i++;j--;
            }
        }
       for(i=0;i<num_stud;i++)
            cout<<b[i]<<" ";
        cout<<endl;
        int t=0;
        for(i=0;i<num_stud;i++)
            if(t<b[i])
                t=b[i];
        if(b[num_stud-1]<mid)
            e=mid-1;
        else if(b[num_stud-1]>mid)
            s=mid+1;
        else
            return mid;
    }
    int t=0;
    for(i=0;i<num_stud;i++)
        if(t<b[i])
            t=b[i];
    return t;
}
int main()
{
    int a[]={10,10,10,10,10,10};
    int n;
    n=sizeof(a)/sizeof(int);
    //cout<<n;
    cout<<min_sum(a,n,3);
    return 0;
}
