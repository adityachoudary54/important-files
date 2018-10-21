#include<iostream>
using namespace std;
int main()
{
    int r[1000],c[1000],cost[4],size_r,size_c,sum_r=0,sum_c=0,sum_all=0,n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        for(int i=0;i<4;i++)
            cin>>cost[i];
        cin>>size_r;
        cin>>size_c;
        for(int i=0;i<size_r;i++)
            cin>>r[i];
        for(int i=0;i<size_c;i++)
            cin>>c[i];
        for(int i=0;i<size_r;i++)
        {
            int sum1=r[i]*cost[0],sum2=cost[1];
            sum_r+=min(sum1,sum2);
        }
        for(int i=0;i<size_c;i++)
        {
            int sum1=c[i]*cost[0],sum2=cost[1];
            sum_c+=min(sum1,sum2);
        }
        sum_r=min(sum_r,cost[2]);
        sum_c=min(sum_c,cost[2]);
        sum_all=sum_r+sum_c;
        sum_all=min(sum_all,cost[3]);
        cout<<sum_all<<endl;
    }
    return 0;
}
