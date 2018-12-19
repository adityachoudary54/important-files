#include <iostream>
#include<algorithm>
using namespace std;
int cost(int a[],int n)
{
    int sum_cost=0;
    sum_cost+=a[0]*(n-1);
    cout<<sum_cost<<", ";
    for(int i=1;i<n;i++)
    {
        sum_cost+=a[i]*(n-i);
        cout<<sum_cost<<", ";
    }
    return sum_cost;
}
int main() {
	//code
	int t;
    int n,a[1000];
	cin>>t;
	for(int i=0;i<t;i++)
	{
	    cin>>n;
	    for(int j=0;j<n;j++)
	        cin>>a[j];
	    sort(a,a+n);
	    cout<<cost(a,n)<<endl;
	}
	return 0;
}
