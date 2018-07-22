#include<iostream>
using namespace std;
void subseq(int input[],int output[],int i, int j,int k,int n)
{
   /* for(int j=0;j<n;j++)
        cout<<output[j]<<" ";
    cout<<endl;*/
    //base case
    int sum=0;
    for(int m=0;m<n;m++)
        sum+=output[m];
    if(sum==k&&i==n)
    {
        for(int p=0;p<j;p++)
        {
                cout<<output[p]<<" ";
        }
        i=0;j=0;
        cout<<endl;
    }
    if(i==n+1)
        return;
    //rec case
  //  cout<<endl;
    output[j]=input[i];//input wala ya toh hoga ya toh nhin hoga
    subseq(input,output,i+1,j+1,k,n);
    output[j]=0;
    //excluding the ith character
    subseq(input,output,i+1,j,k,n);
}
int main()
{
    int a[]={1,2,3,4};
    int b[]={0,0,0,0};
  //  for(int i=1;i<=10;i++)
  //  {
        subseq(a,b,0,0,3,4);
   //     cout<<endl;
   // }

}
