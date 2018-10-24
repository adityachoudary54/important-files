#include<iostream>
using namespace std;
long long int tiling_problem(int n)
{
    if(n==0)
        return 1;
    if(n>=2)
    {
        return tiling_problem(n-1)+tiling_problem(n-2);
    }
    else
        return tiling_problem(n-1);
}
int main()
{
    int t,n;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        cin>>n;
        cout<<tiling_problem(n)<<endl;
    }
}
