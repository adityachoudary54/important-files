#include<iostream>
using namespace std;
int main()
{
    int n,k,l,nl,c,d,p,np,i;
    long int a[3],mini;
    cin>>n>>k>>l>>c>>d>>p>>nl>>np;
    a[0]=(k*l)/nl;
    a[1]=c*d;
    a[2]=p/np;
    for(i=0;i<3;i++)
    {
        if(i==0)
            mini=a[0];
        if(mini>a[i])
            mini=a[i];
    }
    cout<<mini/n;
}
