#include<iostream>
#include<math.h>
using namespace std;
int main()
{
    int i,n,k;
    k=0;
    cin>>n;
    for(i=1;i<=sqrt(n);i++)
    {
        if(n%i==0)
            k++;
    }
    if(k==1)
        cout<<"prime";
    else
        cout<<"not prime";
    return 0;

}
