#include<iostream>
using namespace std;
int main()
{
    int a[3][2],b[4],i,j;
    for(i=0;i<3;i++)
    {
        for(j=0;j<2;j++)
            cin>>a[i][j];
    }
    b[0]=(a[0][0]-a[1][1]+a[2][0])/2;
    b[3]=(a[1][1]-a[0][0]+a[2][0])/2;
    b[1]=(a[0][0]-a[1][0]+a[2][1])/2;
    b[2]=(a[1][0]-a[0][0]+a[2][1])/2;
    for(i=0;i<4;i++)
    {
        for(j=i+1;j<4;j++)
        {
            if(b[i]==b[j]||b[i]>9||b[j]>9||b[i]<=0||b[j]<=0)
            {
                cout<<-1;
                return 0;
            }
        }
    }
    if((b[0]+b[1]==a[0][0])&&(b[2]+b[3]==a[0][1])&&(b[0]+b[2]==a[1][0])&&(b[1]+b[3]==a[1][1])&&(b[0]+b[3]==a[2][0])&&(b[2]+b[1]==a[2][1]))
    {
        cout<<b[0]<<" "<<b[1]<<endl;
        cout<<b[2]<<" "<<b[3]<<endl;
    }
    else
    {
        cout<<-1;
    }
    return 0;
}
