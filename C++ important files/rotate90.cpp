#include<iostream>
using namespace std;
int main()
{
    int i,j,a[10][10],b[10][10],t;
    int n;
    cin>>n;
    t=0;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            t++;
            a[i][j]=t;
        }
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
            cout<<a[i][j]<<" ";
        cout<<endl;
    }
    for(i=0;i<n;i++)// pehle transpose kia
    {
        for(j=i;j<n;j++)
        {
            if(i!=j)
            swap(a[i][j],a[j][i]);
        }
    }
    for(j=0;j<n/2;j++)//phir transpose ko plt dia
    {
        for(i=0;i<n;i++)
        {
            swap(a[i][j],a[i][n-j-1]);
        }
    }
    for(int k=0;k<n;k++)
        {
            for(int l=0;l<n;l++)
                cout<<a[k][l]<<" ";
            cout<<endl;
        }
    return 0;
}
