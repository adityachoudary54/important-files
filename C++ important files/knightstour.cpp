#include<iostream>
using namespace std;
int knightchk(int i_pos,int j_pos,int a[][8],int n)
{
    if(((i_pos)>=0&&(i_pos)<n)&&(a[i_pos][j_pos]<1)&&((j_pos)>=0&&(j_pos)<n))
    {
        //cout<<i_pos<<" "<<j_pos;
        return true;
    }
    return false;
}
int t=1;
long int k=0;
int knighttour(int a[][8],int n,int i_pos,int j_pos)
{   k++;
    int pos_move[][2]={{2,1},{1,2},{-1,2},{-2,1},{-2,-1},{-1,2},{1,-2},{-1,-2},{2,-1}};
    if(t==n*n)
    {
        a[i_pos][j_pos]=t;
        return 1;
    }
    a[i_pos][j_pos]=t;
   /* for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            cout<<a[i][j]<<" ";
        cout<<endl;
    }
    cout<<endl;*/
    for(int i=0;i<8;i++)
    {
        if(knightchk(i_pos+pos_move[i][0],j_pos+pos_move[i][1],a,n))
        {
            t++;
            if(knighttour(a,n,i_pos+pos_move[i][0],j_pos+pos_move[i][1]))
                return t;
        }
    }
    t--;
    a[i_pos][j_pos]=0;
    return 0;
}
int main()
{
    int a[8][8];
    int i,j,n;
    cin>>n;
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
        a[i][j]=0;
    cout<<knighttour(a,n,0,0)<<endl;
   for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            cout<<a[i][j]<<" ";
        cout<<endl;
    }
    cout<<k;
    return 0;
}










