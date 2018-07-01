#include<iostream>
#include<math.h>
using namespace std;
int main()
{
    int i,n,sq,j;
    cin>>n;
    sq=sqrt(n*2);
    for(i=1;i<=sq;i++)
        for(j=1;j<=i;j++)
            if(i*i +i +j*j +j ==n*2)
                return cout<<"YES",0;
    return cout<<"NO",0;
}
