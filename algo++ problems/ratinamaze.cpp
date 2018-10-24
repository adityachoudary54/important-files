#include<iostream>
using namespace std;
bool helper(char a[][7],int I,int J,int m,int n)
{
    if(a[I][J]!='X'&&I<=m&&J<=n)
        return true;
    return false;
}

void disp(char a[][7],int n)
{
    for(int I=0;I<4;I++)
    {
        for(int J=0;J<6;J++)
            cout<<a[I][J]<<" ";
        cout<<endl;
    }
}
int cnt=0;
int rattrack(char a[][7],int i,int j,int m,int n)
{
    if(i==m&&j==n)
    {
        a[i][j]='M';
        disp(a,n);
        cout<<endl;
        cnt++;
        return 0;
    }
    if(helper(a,i,j,m,n))
    {
        a[i][j]='M';
        if(rattrack(a,i+1,j,m,n))
        {
            return 1;
        }
        if(rattrack(a,i,j+1,m,n))
        {
            return 1;
        }
        a[i][j]='0';
    }
    return 0;
}
int main()
{
    char a[4][7]={"000000","0XXX00","0XXX00","X000X0"};
    int I,J;
    for(I=0;I<4;I++)
    {
        for(J=0;J<6;J++)
            cout<<a[I][J]<<" ";
        cout<<endl;
    }
    cout<<endl;
    rattrack(a,0,0,3,5);
    cout<<cnt;
    return 0;
}
