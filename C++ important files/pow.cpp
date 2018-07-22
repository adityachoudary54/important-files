#include<iostream>
using namespace std;
int pow(int x,int n)
{
    int t;
    if(n<=0)
        return 1;
    if(n&1)
    {
        return x*pow(x,n-1);
    }
    else
    {
        t=pow(x,n/2);
        return t*t;
    }
}
int main()
{
    int x,n;
    cin>>x>>n;
    cout<<pow(x,n);
}
