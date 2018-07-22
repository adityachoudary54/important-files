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
   // cout << endl << endl;
    return true;
}
bool nqueen(char a[][100],int j,int n)
{
    int i;
    if(j>=n)
    {
        return true;
    }
    for(i=0;i<n;i++)
    {
        if(helper(a,i,j,n))
        {
            a[i][j]='Q';
            if(nqueen(a,j+1,n))
                return true;
            a[i][j]='X';
        }
    }
    return false;
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
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
            cout<<a[i][j]<<"   ";
        cout<<endl<<endl;
    }
    return 0;
}
