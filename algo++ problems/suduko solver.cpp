#include<iostream>
#include<math.h>
using namespace std;
void printarr(int a[][9],int num)
{
    int i,j;
    int t;
    t=sqrt(num);
    for(i=0;i<num;i++)
    {
        for(j=0;j<num;j++)
        {
            cout<<a[i][j]<<" ";
            if((j+1)%t==0&&j!=num-1)
                cout<<"* ";
        }
        cout<<endl;
        if((i+1)%t==0&&i!=num-1)
                cout<<"*********************"<<endl;
    }

}
int canPlace(int a[][9],int row,int col,int n,int val)
{
    for(int i=0;i<n;i++)
    {
        if(a[row][i]==val||a[i][col]==val)
            return 0;
    }
    int rtn=sqrt(n);
    int sx=(row/rtn)*rtn;
    int sy=(col/rtn)*rtn;
    for(int i=sx;i<sx+rtn;i++)
    {
        for(int j=sy;j<sy+rtn;j++)
        {
            if(a[i][j]==val&&i!=row&&j!=col)
                return 0;
        }
    }
    return 1;
}
int suduko_solver(int a[][9],int i,int j,int n)
{
    if(i==n&&j==n)
    {
        printarr(a,9);
        cout<<endl;
        return 0;
    }
    if(j==n)
    {
        return suduko_solver(a,i+1,0,n);
    }
    if(a[i][j]!=0)
    {
        return suduko_solver(a,i,j+1,n);
    }
    for(int val=1;val<=n;val++)
    {
        if(canPlace(a,i,j,n,val))
        {
            a[i][j]=val;
            if(suduko_solver(a,i,j+1,n))
            {
                return 1;
            }
        }
    }
    a[i][j]=0;
    return 0;
}
int main()
{
    int a[9][9]={{3, 0, 6, 5, 0, 8, 4, 0, 0},
                {5, 2, 0, 0, 0, 0, 0, 0, 0},
                {0, 8, 7, 0, 0, 0, 0, 3, 1},
                {0, 0, 3, 0, 1, 0, 0, 8, 0},
                {9, 0, 0, 8, 6, 3, 0, 0, 5},
                {0, 5, 0, 0, 9, 0, 6, 0, 0},
                {1, 3, 0, 0, 0, 0, 2, 5, 0},
                {0, 0, 0, 0, 0, 0, 0, 7, 4},
                {0, 0, 5, 2, 0, 6, 3, 0, 0}};
    suduko_solver(a,0,0,9);
    return 0;
}
