#include<iostream>
using namespace std;
int main()
{
    int i,j,t,tot,endi,rev;
    char a[10][10];
    int n;
    char b[]="OX";
    cin>>n;
    t=0;
    i=0;j=0;tot=0,endi=0;rev=0;
    while(tot<(n*n))
    {
        if(i==(0+endi)&&j!=(n-1-endi))
        {
            a[i][j]=b[rev];
            j++;tot++;
        }
        else if(j==(n-1-endi)&&i!=(n-1-endi))
        {
            a[i++][j]=b[rev];tot++;
        }
        else if(i==(n-1-endi)&&j!=(0+endi))
        {
            a[i][j--]=b[rev];tot++;
        }
        else if(j==(0+endi)&&i!=(0+endi+1))
        {
            a[i--][j]=b[rev];tot++;
        }
        else if(i==(0+endi+1))
        {
            a[i][j]=b[rev];tot++;
            if(rev)
                rev=0;
            else
                rev=1;
            endi++;
            j++;
        }
   // cout<<endl;
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
            cout<<a[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}

