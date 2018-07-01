#include<iostream>
using namespace std;
int main()
{
    int n,m,suc,i,j,c[100];
    char p,a[100][100];
    cin>>n>>m;
    for(i=0;i<n;i++)
    {   c[i]=0;
         for(j=0;j<m;j++)
            cin>>a[i][j];
    }
    suc=0;
    for(j=0;j<m;j++)
    {   p='0';
        for(i=0;i<n;i++)
        {
            if(a[i][j]>p)
            {
                p=a[i][j];
            }
        }
        for(i=0;i<n;i++)
        {
            if(p==a[i][j])
            {
                c[i]++;
            }
        }
    }
    for(i=0;i<n;i++)
    {
        if(c[i]!=0)
            suc++;
    }
    cout<<suc;
}
