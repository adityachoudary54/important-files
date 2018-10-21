#include<iostream>
using namespace std;
int main()
{
    int a[10][10],m,n;
    cin>>m>>n;
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>a[i][j];
        }
    }
    for(int j=0;j<n;j++)
    {
        if(j&1)
        {
            for(int i=m-1;i>=0;i--)
            {
                cout<<a[i][j]<<" ";
            }
        }
        else
        {
            for(int i=0;i<m;i++)
            {
                cout<<a[i][j]<<" ";
            }
        }
    }
    return 0;
}
