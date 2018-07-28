#include<iostream>
using namespace std;
//recursive approach to this problem
int minCoins(int amnt,int coins[],int n)
{
    if(amnt<=0)
        return amnt;
    int mini,t;
    mini=INT_MAX;
    for(int i=0;i<n;i++)
    {
        if(amnt-coins[i]>=0)
        {
            t=minCoins(amnt-coins[i],coins,n)+1;
            //cout<<t<<endl;
            if(t<mini)
                mini=t;
        }
        else
            break;
    }
    return mini;
}

//DP approach(Bottom up DP)
int minCoinsDP(int amnt,int coins[],int n,int *dp)
{
    //int *dp=new int[amnt+1];
    dp[0]=0;
    for(int rupay=1;rupay<=amnt;rupay++)
    {
        //iterate over coins
        for(int i=0;i<n;i++)
        {
            if(coins[i]<=rupay)
            {
                int smallerAns=dp[rupay-coins[i]];
                if(smallerAns!=INT_MAX)
                {
                    dp[rupay]=min(dp[rupay],smallerAns+1);
                }
            }
        }
    }
    return dp[amnt];
}

int main()
{
    int us_coins[]={1,7,10};
    int ind_coins[]={1,2,5,10,50};
    int n=5;
    int amnt=39;
    int dp[10000];
    for(int i=0;i<=amnt;i++)
    {
        dp[i]=INT_MAX;
    }
    cout<<minCoins(amnt,ind_coins,n,dp);
}
