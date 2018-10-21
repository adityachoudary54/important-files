#include<iostream>
#include<limits.h>
using namespace std;
int main()
{
    int a[]={-4,1,3,-2,6,2,-1,-4,-7},sum=INT_MIN,left=0,right=0;
    int size=sizeof(a)/sizeof(int);
    int *csum=new int[size];
    csum[0]=a[0];
    for(int i=1;i<size;i++)
    {
        csum[i]=csum[i-1]+a[i];
    }
    for(int i=0;i<size;i++)
    {
        for(int j=i;j<size;j++)
        {
            int sum_arr;
            if(i>0)
                sum_arr=csum[j]-csum[i-1];
            else
                sum_arr=csum[j];
            if(sum_arr>sum)
            {
                sum=sum_arr;
                left=i;
                right=j;
            }
        }
    }
    cout<<"Maximum sum is:"<<sum<<" b/w "<<left<<","<<right<<endl;
    return 0;
}




