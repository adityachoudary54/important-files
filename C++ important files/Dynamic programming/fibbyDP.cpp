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
int main()
{
	int n;
	cin>>n;
	long long int dp[1000];
	for(int i=0;i<=n;i++)
		dp[i]=-1;
	cout<<topdowndp(n,dp);
	//cout<<fib(n);
	return 0;
}
