#include<iostream>
using namespace std;
int largest_subseq_rec(int input[],int output[],int n,int i,int j)
{
    if(i==n)
    {
        int t=0;
        for(int k=0;k<j-1;k++)
        {
            if(output[k]<output[k+1])
            {
               // cout<<output[k]<<" ";
                if(t==0)
                    t=2;
                else
                    t++;
            }
            else
                break;
        }
       // cout<<endl;
        return t;
    }
    output[j]=input[i];
    int l1=largest_subseq_rec(input,output,n,i+1,j+1);
    int l2=largest_subseq_rec(input,output,n,i+1,j);
    return max(l1,l2);
}
int largest_subseq_dp(int input[],int n)
{
    int *dp=new int[n];
    for(int i=0;i<n;i++)
        dp[i]=1;
    int i,j,res;
    res=INT_MIN;
    for(i=1;i<n;i++)
    {
        j=i-1;
        int maxi=INT_MIN;
        while(j>=0)
        {
            if(input[i]>input[j])
            {
                if(maxi==INT_MIN)
                    maxi=dp[j];
                else if(dp[j]>maxi)
                    maxi=dp[j];
            }
            j--;
        }
        if(maxi!=INT_MIN)
            dp[i]=maxi+dp[i];
        if(dp[i]>res)
            res=dp[i];
    }
    return res;
}
int main()
{
    int input[100],output[100],n;
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>input[i];
    cout<<largest_subseq_dp(input,n);
    return 0;
}
