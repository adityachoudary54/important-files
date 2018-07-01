#include<iostream>
using namespace std;
struct one
{
    int x,y;
}a;
int main()
{
    int b[5][5],i,j;
    for(i=0;i<5;i++)
        for(j=0;j<5;j++)
        cin>>b[i][j];
    for(i=0;i<5;i++)
    {
        for(j=0;j<5;j++)
       {
            if(b[i][j]==1)
            {
                a.x=i;
                a.y=j;
            }
       }
    }
    a.x=a.x-2;
    a.y=a.y-2;
    if(a.x<0)
        a.x=a.x*-1;
    if(a.y<0)
        a.y=a.y*-1;
    cout<<a.x+a.y;
}
