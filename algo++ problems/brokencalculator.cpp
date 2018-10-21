#include<iostream>
using namespace std;
void brokencalc(int n)
{
    int a[2000];
    for(int i=0;i<1999;i++)
        a[i]=0;
    a[0]=1;
    for(int i=1;i<=n;i++)
    {
        int carry=0;
        for(int j=0;j<1999;j++)
        {
            int prod;
            prod=a[j]*i+carry;
            a[j]=prod%10;
            carry=prod/10;
        }
    }
    int i=1998;
    while(a[i]==0)
        i--;
    for(;i>=0;i--)
        cout<<a[i];
}
int main()
{
    int n;
    cin>>n;
    brokencalc(n);
}
