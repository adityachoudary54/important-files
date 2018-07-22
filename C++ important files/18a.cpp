#include<iostream>
#include<math.h>
using namespace std;
struct point
{
    int x;
    int y;
}a[3];
bool tri(point a[3])
{
    int d[3];
    //bool r=false;
    d[0]=pow((a[0].x-a[1].x),2)+pow((a[0].y-a[1].y),2);
    d[1]=pow((a[1].x-a[2].x),2)+pow((a[1].y-a[2].y),2);
    d[2]=pow((a[0].x-a[2].x),2)+pow((a[0].y-a[2].y),2);
    if(d[0]>d[1]&&d[0]>d[2])
    {
        if(d[0]==(d[1]+d[2]))
            return true;
    }
    else if(d[1]>d[2]&&d[1]>d[0])
    {
        if(d[1]==(d[0]+d[2]))
            return true;
    }
    else if(d[2]>d[1]&&d[2]>d[0])
    {
        if(d[2]==(d[0]+d[1]))
            return true;
    }
    return false;
}
int main()
{
    int i,j;
    for(i=0;i<3;i++)
    {
       cin>>a[i].x>>a[i].y;
    }
    if(tri(a))
    {
        cout<<"RIGHT";
        return 0;
    }
    for(i=0;i<3;i++)
    {
        a[i].x+=(-1);
        if(tri(a))
        {
            cout<<"ALMOST";
            return 0;
        }
        a[i].x+=2;
        if(tri(a))
        {
            cout<<"ALMOST";
            return 0;
        }
        a[i].x+=(-1);
        a[i].y+=(-1);
        if(tri(a))
        {
            cout<<"ALMOST";
            return 0;
        }
        a[i].y+=2;
        if(tri(a))
        {
            cout<<"ALMOST";
            return 0;
        }
        a[i].y+=(-1);
    }
    cout<<"NEITHER";
    return 0;
}


























