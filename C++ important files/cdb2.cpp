#include<iostream>
using namespace std;
int fact(int n);
int main()
{
    int n;
    cin>>n;
    cout<<fact(n);
}
int fact(int n)
{
    if(n==0)
        return 1;
    else
        return n*fact(n-1);
}
