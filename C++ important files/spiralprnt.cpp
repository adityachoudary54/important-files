#include<iostream>
using namespace std;
int main()
{
    int i,j,a[10][10],b[10][10],t,tot,endi;
    int m,n;
    cin>>m>>n;
    t=0;
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            t++;
            a[i][j]=t;
            //cout<<a[i][j]<<" ";
        }
        //cout<<endl;
    }i=0;j=0;tot=0,endi=0;
    while(tot<(m*n))
    {
        if(i==(0+endi)&&j!=(n-1-endi))
        {
            cout<<a[i][j]<<" ";
            j++;tot++;
        }
        else if(j==(n-1-endi)&&i!=(m-1-endi))
        {
            cout<<a[i++][j]<<" ";tot++;
        }
        else if(i==(m-1-endi)&&j!=(0+endi))
        {
            cout<<a[i][j--]<<" ";tot++;
        }
        else if(j==(0+endi)&&i!=(0+endi+1))
        {
            cout<<a[i--][j]<<" ";tot++;
        }
        else if(i==(0+endi+1))
        {
            cout<<a[i][j]<<" ";tot++;
            endi++;
            j++;
        }
    }
    return 0;
}
