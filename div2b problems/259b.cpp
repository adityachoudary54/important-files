#include<iostream>
using namespace std;
int main()
{
    int a[3][3],d=0;
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            cin>>a[i][j];
        }
    }
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            if(a[i][j]!=0)
                d+=a[i][j];
    d=d/2;
    for(int i=0;i<3;i++)
    {
        int sum=0;
        for(int j=0;j<3;j++)
        {
            if(i!=j)
                sum+=a[i][j];
        }
        a[i][i]=d-sum;
    }
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
