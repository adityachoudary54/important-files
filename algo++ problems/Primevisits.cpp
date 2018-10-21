#include<iostream>
using namespace std;
int prime_visits(int x,int y)
{
    int a[100001];
    a[1]=a[0]=0;
    for(int i=2;i<=100000;i++)
        a[i]=1;
    for(int i=2;i*i<=100000;i++)
    {
        if(a[i])
        {
            for(int j=i*2;j<=100000;j+=i)
            {
                a[j]=0;
            }
        }
    }
    int cnt=0;
    for(int i=x;i<=y;i++)
    {
        if(a[i])
            cnt++;
    }
    return cnt;
}
int main()
{
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        int a,b;
        cin>>a>>b;
        cout<<prime_visits(a,b)<<endl;
    }
}
