#include<iostream>
#include<set>
using namespace std;
void T_prime(long long q[],long long n)
{
    //cout<<"hello";
    long long p[1000001];
    long long i,j;
    p[0]=p[1]=0;
    p[2]=1;
    for(i=3;i<=1000000;i++)
    {
        if(i&1)
            p[i]=1;
        else
            p[i]=0;
    }
    for(i=3;i*i<=1000000;i+=2)
    {
        if(p[i])
        {
            for(j=i*i;j<=1000000;j+=2*i)
            {
                p[j]=0;
            }
        }
    }
    set<long long int> v;
    for(i=2;i<=1000000;i++)
    {
        if(p[i])
        {
            //cout<<i*i<<endl;
            v.insert(i*i);
        }
    }
    for(i=0;i<n;i++)
    {
        if(v.find(q[i])!=v.end())
        {
            cout<<"YES"<<endl;
        }
        else
        {
            cout<<"NO"<<endl;
        }
    }
}
int main()
{
    long long n,a[100000];
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
   // cout<<"hello";
    T_prime(a,n);
}
