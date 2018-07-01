#include<iostream>
using namespace std;
int main()
{
    long long int i,n,k,l;
    cin>>k>>l;
    for(i=0,n=k;n<l;n=n*k,i++);
    if(n==l)
    {
        cout<<"YES"<<endl;
        cout<<i;
    }
    else
    {
        cout<<"NO";
    }
    return 0;
}
