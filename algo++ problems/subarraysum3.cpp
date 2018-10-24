#include<iostream>
#include<limits.h>
using namespace std;
int main()
{
    int a[]={-4,1,3,-2,6,2,-1,-4,-7},cs=0,ms=0,left=0,right=0;
    int size=sizeof(a)/sizeof(int);
    for(int i=0;i<size;i++)
    {
        cs=cs+a[i];
        if(cs<0)
        {
            cs=0;
        }
        if(ms<cs)
            ms=cs;
    }
    cout<<"Maximum sum is:"<<ms<<endl;
    return 0;
}





