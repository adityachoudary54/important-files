#include<iostream>
using namespace std;
long long  int fibi[200];
int fib(int n)
{
    if(n<=0)
        return 0;
    else if(n==1)
        return 1;
    else
        if(fibi[n-1]==-1)
        	fibi[n-1]=fib(n-1);
 		if(fibi[n-2]==-1)
        	fibi[n-2]=fib(n-2);
        return fibi[n-1]+fibi[n-2];

}
int main()
{
	fibi[0]=0;
	fibi[1]=1;
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    	fibi[i]=-1;
    cout<<fib(n);
}
