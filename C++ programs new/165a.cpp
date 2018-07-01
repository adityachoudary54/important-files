#include<iostream>
using namespace std;
struct point
{
    int x,y;
}a[200];
int main()
{
    int i,j,n,t,b[4],k,u;
    t=u=0;
    for(i=0;i<4;i++)
    {
        b[i]=0;
    }
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>a[i].x>>a[i].y;
    }
    for(i=0;i<n;i++)
    {   t=0;
        for(k=0;k<=3;k++)
        {
            b[k]=0;
        }
        for(j=0;j<n;j++)
        {   if(j!=i)
            {
            if((a[i].x==a[j].x)&&(a[i].y<a[j].y))
                b[0]=1;
            else if((a[i].x==a[j].x)&&(a[i].y>a[j].y))
                b[1]=1;
            else if((a[i].x<a[j].x)&&(a[i].y==a[j].y))
                b[2]=1;
            else if((a[i].x>a[j].x)&&(a[i].y==a[j].y))
                b[3]=1;
            }
        }
        for(k=0;k<=3;k++)
        {
            if(b[k]==1)
                t++;
        }
        if(t==4)
            u++;
    }
    cout<<u;
}
