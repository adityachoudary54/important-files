#include<iostream>
using namespace std;
int main()
{
    int a[100],n,b[100],i,j;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
        b[i]=i+1;
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(b[i]==a[j])
            {
                b[i]=j+1;
                break;
            }
        }
    }
    for(i=0;i<n;i++)
        cout<<b[i]<<" ";
}
