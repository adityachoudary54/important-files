#include<iostream>
#include<vector>
using namespace std;
int rec(int coins[],int change,int n)
{
	int ways=0;
	if(change==0)
	{
		ways++;
		return ways;
	}
	for(int i=0;i<n;i++)
	{
		if(coins[i]<=change)
		{
			ways+=rec(coins,change-coins[i],n);
		}
	}
	return ways;
}
int bottomup(int coins[],int change,int n)
{
    int *dp=new int[change+1];
    dp[0]=0;
    dp[1]=1;
    for(int i=2;i<=change;i++)
    {
        dp[i]=0;
        for(int j=0;j<n;j++)
        {
            if(i-coins[j]>0)
            {
                dp[i]+=dp[i-coins[j]];
            }
            else if(i-coins[j]==0)
            {
                dp[i]++;
            }
        }
    }
    return dp[change];
}

//perform also by linear recurrence
int main()
{
	int j,a[]={1,2,5};
	cout<<bottomup(a,5,3);
}
