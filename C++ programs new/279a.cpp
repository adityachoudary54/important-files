#include<iostream>
using namespace std;
struct coordinate
{
    int x,y;
}a;
int main()
{
    int y,x,i,n;
    cin>>a.x>>a.y;
    if(a.x==0&&a.x==a.y)
        cout<<0;
    else if(a.y>0&&a.y==a.x)
    {
        cout<<(a.y-1)*4+1;
    }
    else if(a.y<0&&a.y==a.x)
    {
        cout<<(-1*a.y-1)*4+3;
    }
    else if(a.y==(-1*a.x+1)&&a.x>=1)
    {
        cout<<(-1*a.y)*4;
    }
    else if(a.y==(-1*a.x)&&a.y>0)
    {
        cout<<(a.y-1)*4+2;
    }
    else if(a.x>a.y&&a.x<(a.y*-1+1))
    {
        cout<<(-1*a.y)*4;
    }
    else if(a.y>(-1*a.x+1)&&a.y<a.x)
    {
        cout<<(a.x-1)*4+1;
    }
    else if(a.x>-a.y&&a.x<a.y)
    {
        cout<<(a.y-1)*4+2;
    }
    else
    {
        cout<<(-1*a.x-1)*4+3;
    }
    return 0;
}
