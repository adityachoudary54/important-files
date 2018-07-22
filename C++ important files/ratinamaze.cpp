#include<iostream>
using namespace std;
bool helper(char a[][7],int I,int J,int m,int n)
{
    if(a[I][J]!='X'&&I<=m&&J<=n)
        return true;
    return false;
}

bool rattrack(char a[][7],int i,int j,int m,int n)
{
    if(i==m&&j==n)
    {
      a[i][j]='M';
        return true;
    }
    if(helper(a,i,j,m,n))//checking whether we can move at the given position or not
    {
        a[i][j]='M';
        if(rattrack(a,i+1,j,m,n))//niche jaake solution mile toh
        {
            return true;
        }
        if(rattrack(a,i,j+1,m,n))//right mei jaake solution mile toh
        {
            return true;
        }
        a[i][j]='0';// for backtracking jb koi solution na mile toh previous function apna dusra alternative dekhega
    }
    return false;
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
    for(I=0;I<4;I++)
    {
        for(J=0;J<6;J++)
            cout<<a[I][J]<<" ";
        cout<<endl;
    }
    return 0;
}


