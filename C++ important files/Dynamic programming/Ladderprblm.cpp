#include<iostream>
using namespace std;
//O(k^n)
int ways(int n)
{
    if(n<0)
        return 0;
    if(n==0)
        return 1;
    return ways(n-1)+ways(n-2)+ways(n-3);
}
int ways2(int n,int k)
{
    if(n<0)
        return 0;
    if(n==0)
        return 1;
    int c=0;
    for(int i=1;i<=k;i++)
    {
        c+=ways2(n-i,k);
    }
    return c;
}
//Top down DP banao


//bottom up DP O(nk)
int waysBU(int n,int k)
{
    int *dp=new int[n+1];
    dp[0]=1;
    for(int step=1;step<=n;step++)
    {
        dp[step]=0;
        for(int j=1;j<=k;j++)
        {
            if(step-j>=0)
            dp[step]+=dp[step-j];
        }
    }
    return dp[n];
}

//can we do it on O(n)???
int waysoptimized(int n,int k)
{
    int *dp=new int[n+1];
    dp[0]=1;
    for(int step=1;step<=n;step++)
    {
        dp[step]=0;
        if(step-k>0)
            dp[step]=2*dp[step-1]-dp[step-k];
        else
        {
            for(int j=1;j<=k;j++)
            {
                if(step-j>=0)
                dp[step]+=dp[step-j];
            }
        }
    }
    return dp[n];
}
int main()
{
    int n,k;
    cin>>n>>k;
    cout<<waysoptimized(n,k);
    return 0;
}
