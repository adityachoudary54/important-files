#include<iostream>
using namespace std;
int main()
{
    int a[100][100],b[100][100],m,n;
    cin>>m>>n;
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>a[i][j];
            b[i][j]=-1;
        }
    }
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(a[i][j]==0)
            {
                for(int k=0;k<n;k++)
                    b[i][k]=0;
                for(int k=0;k<m;k++)
                    b[k][j]=0;
            }
        }
    }
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(b[i][j]==-1)
            {
                for(int k=0;k<n;k++)
                {
                    if(a[i][k]==1)
                    {
                        b[i][j]=1;
                        break;
                    }
                }
                for(int k=0;k<m;k++)
                {
                    if(a[k][j]==1)
                    {
                        b[i][j]=1;
                        break;
                    }
                }
            }
        }
    }
    if(cnt1==cnt2)
    {
        cout<<"YES"<<endl;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                cout<<b[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    else
    {
        cout<<"NO";
    }
    return 0;
}
