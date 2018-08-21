#include<iostream>
using namespace std;
int binom(int n,int m)
{
    if(m==0||(n-m)==0)
    {
        return 1;
    }
    else
    {
        return binom(n-1,m)+binom(n-1,m-1);
    }
}
int binomialCoeff(int n, int k)//best method
{
    int res = 1;

    // Since C(n, k) = C(n, n-k)
    if ( k > n - k )
        k = n - k;

    // Calculate value of [n * (n-1) *---* (n-k+1)] / [k * (k-1) *----* 1]
    for (int i = 0; i < k; ++i)
    {
        res *= (n - i);
        res /= (i + 1);
    }

    return res;
}
int main()
{
    int n,m;
    cin>>n>>m;
    cout<<binom(n,m);
    return 0;
}
