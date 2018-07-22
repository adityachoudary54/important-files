#include<iostream>
using namespace std;
bool helper(char a[][100],int I,int J,int n)
{
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(a[i][j]=='Q'&&(i==I||(((j-J)!=0)&&((i-I)==(j-J))||((i-I)==(J-j)))))
                return false;
        }
    }
    return true;
}
long int cnt=0;
bool nqueen(char a[][100],int j,int n)
{
    int i;

    if(j>=n)
    {
        cnt++;
        return true;
    }
    bool r=false;
    for(i=0;i<n;i++)
    {
        if(helper(a,i,j,n))
        {
            a[i][j]='Q';
            if(nqueen(a,j+1,n))
            {
                r=true;
            }
            a[i][j]='X';
        }
    }
    return r;
}

int main()
{
    char a[100][100];
    int n,i,j;
    cin>>n;
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            a[i][j]='X';
    nqueen(a,0,n);
    cout<<"Possible configurations are:"<<cnt;
    return 0;
}
