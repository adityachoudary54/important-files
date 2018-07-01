#include<iostream>
using namespace std;
struct game
{
    int x,y;
}a[30];
int main()
{
    int i,j,k,n;
    k=0;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>a[i].x>>a[i].y;
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if((a[i].x==a[j].y)&&(i!=j))
                k++;
        }
    }
    cout<<k;
}
