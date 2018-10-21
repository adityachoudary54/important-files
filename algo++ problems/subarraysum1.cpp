#include<iostream>
#include<limits.h>
using namespace std;
int main()
{
    int a[]={-4,1,3,-2,6,2,-1,-4,-7},sum=INT_MIN;
    int size=sizeof(a)/sizeof(int);
    for(int i=0;i<size;i++)
    {
        for(int k=i;k<size;k++)
        {
            int temp=0;
            for(int j=i;j<=k;j++)
                temp+=a[j];
            if(temp>sum)
                sum=temp;

        }
    }
    cout<<sum<<endl;
    return 0;
}
