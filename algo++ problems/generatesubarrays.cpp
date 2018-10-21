#include<iostream>
using namespace std;
int main()
{
    int a[]={1,2,3,4};
    for(int i=0;i<4;i++)
    {
        for(int k=i;k<4;k++)
        {
            for(int j=i;j<=k;j++)
                cout<<a[j]<<" ";
            cout<<endl;
        }
    }
    return 0;
}
