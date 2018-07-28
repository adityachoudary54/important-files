#include<iostream>
using namespace std;
int waysToOne(int n)
{
    if(n==1)
    {
        return 0;
    }
    int way1=INT_MAX,way2=INT_MAX,way3=INT_MAX;
    if(n%2==0)
        way1=waysToOne(n/2)+1;
    if(n%3==0)
        way2=waysToOne(n/3)+1;
    way3=waysToOne(n-1)+1;
    return min(way1,min(way2,way3));
}
int waysToOnebottomup(int n)
{
    int *dp=new int[n+1];
    int way1,way2,way3;
    dp[1]=0;
    for(int i=2;i<=n;i++)
    {
        way1=way2=way3=INT_MAX;
        if(i%2==0)
            way1=dp[i/2]+1;
        if(i%3==0)
            way2=dp[i/3]+1;
        if((i-1)!=0)
            way3=dp[i-1]+1;
       // cout<<way1<<" "<<way2<<" "<<way3<<endl;
        dp[i]=min(way1,min(way2,way3));
    }
   /* for(int i=1;i<=n;i++)
        cout<<dp[i]<<" ";*/
   // cout<<endl;
    return dp[n];
}
int main()
{
    cout<<waysToOne(100)<<endl;
    cout<<waysToOnebottomup(100)<<endl;
    return 0;
}
