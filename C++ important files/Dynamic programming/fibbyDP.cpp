#include<iostream>
using namespace std;
long long int fib(int n)
{
	if(n==0||n==1)
		return n;
	return fib(n-1)+fib(n-2);
}

long long int topdowndp(int n,long long int dp[])
{
	if(n==0||n==1)
	{
	    dp[n]=n;
		return dp[n];
	}
	if(dp[n]!=-1)
		return dp[n];
	else
		dp[n]=topdowndp(n-1,dp)+topdowndp(n-2,dp);
		return dp[n];
}

int fibBottomUp(int n)
{
    //generally bottomup in DP is iterarive approach
    int *dp=new int[n+1];
    dp[0]=0;
    dp[1]=1;
    for(int i=2;i<=n;i++)
    {
        dp[i]=dp[i-2]+dp[i-1];
    }
    return dp[n];
    //it can be done by this way also
  /*  int a,b;
    a=0;
    b=1;
    if(n<2)
        return n;
    for(int i=2;i<=n;i++)
    {
        int c;
        c=b;
        b=a+b;
        a=c;
    }
    return b; */
}
int main()
{
	int n;
	cin>>n;
	long long int dp[1000];
	for(int i=0;i<=n;i++)
		dp[i]=-1;
	cout<<fibBottomUp(n);
	//cout<<fib(n);
	return 0;
}
