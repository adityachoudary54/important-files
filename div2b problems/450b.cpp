#include<iostream>
using namespace std;
void multi(int a[][2],int b[][2])
{
    int i,j,mul[2][2];
    for(int i=0;i<2;i++)
    {
        for(int j=0;j<2;j++)
        {
            mul[i][j]=0;
        }
    }
    for(i=0;i<2;i++)
    {
        for(j=0;j<2;j++)
        {
            for(int k=0;k<2;k++)
            {
                mul[i][j]+=a[i][k]*b[k][j];
                //cout<<mul[i][j];
            }
        }
    }
    for(int i=0;i<2;i++)
    {
        for(int j=0;j<2;j++)
        {
            a[i][j]=mul[i][j];
        }
    }
}
void pow(int a[][2],int b[][2],int n)
{
    if(n==1)
    {
        return ;
    }
    if(n&1)
    {
        pow(a,b,n-1);
        multi(a,b);
    }
    else
    {
        pow(a,b,n/2);
        multi(a,a);
    }
}
int main()
{
    int f1,f2,n;
    int a[2][2]={{0,1},{-1,1}};
    int b[2][2]={{0,1},{-1,1}};
    cin>>f1>>f2>>n;
    if(n>2)
    {
        pow(a,b,n-2);
        int fn=f1*a[1][0]+f2*a[1][1];
       /* cout<<a[0][0]<<" "<<a[0][1]<<endl;
        cout<<a[1][0]<<" "<<a[1][1]<<endl;*/
        //cout<<fn<<endl;
        if(fn>=0)
            cout<<fn%1000000007;
        else
            cout<<(((-fn)-1)/1000000007+1)*1000000007+fn;
    }
    else
    {
        if(n==1)
        {
            if(f1>=0)
            cout<<f1%1000000007;
            else
            cout<<(((-f1)-1)/1000000007+1)*1000000007+f1;
        }
        else
        {
            if(f2>=0)
            cout<<f2%1000000007;
            else
            cout<<(((-f2)-1)/1000000007+1)*1000000007+f2;
        }
    }
    return 0;
}
