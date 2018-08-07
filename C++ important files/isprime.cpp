#include<iostream>
using namespace std;
bool isprime(int n)
{
    if(n==1)
        return false;
    if(n==2)
        return true;
    if(n%2==0)
        return false;
    for(int i=3;i*i<=n;i+=2)
    {
        if(n%i==0)
            return false;
    }
    return true;
}
bool sieveoferatosthenes(int n)
{
    int a[1000];
    a[1]=a[0]=0;
    for(int i=2;i<=n;i++)
        a[i]=1;
    for(int i=2;i*i<=n;i++)
    {
        if(a[i])
        {
            for(int j=i*2;j<=n;j+=i)
            {
                a[j]=0;
            }
        }
    }
    /*for(int i=1;i<=n;i++)
    {
        cout<<a[i]<<" ";
        if(i%10==0)
            cout<<endl;
    }*/
    return a[n];
}

bool optimized_sieveoferatosthenes(int n)
{
    int a[1000];
    a[1]=a[0]=0;
    a[2]=1;
    for(int i=3;i<=n;i++)
    {
        if(i&1)
            a[i]=1;
        else
            a[i]=0;
    }
    for(int i=3;i*i<=n;i+=2)
    {
        if(a[i])
        {
            for(int j=i*i;j<=n;j+=i)
            {
                a[j]=0;
            }
        }
    }
   /* for(int i=1;i<=n;i++)
    {
        cout<<a[i]<<" ";
        if(i%10==0)
            cout<<endl;
    }*/
    return a[n];
}

bool fastest_prime(int n)
{
    int a[1000];
    a[1]=a[0]=0;
    a[2]=1;
    for(int i=3;i<=n;i++)
    {
        if(i&1)
            a[i]=1;
        else
            a[i]=0;
    }
    for(int i=3;i*i<=n;i+=2)
    {
        if(a[i])
        {
            for(int j=i*i;j<=n;j+=2*i)
            {
                a[j]=0;
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        cout<<a[i]<<" ";
        if(i%10==0)
            cout<<endl;
    }
    return a[n];
}
int main()
{
    int n;
    cin>>n;
    cout<<fastest_prime(n);
}
