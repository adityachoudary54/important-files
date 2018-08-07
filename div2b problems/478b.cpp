#include<iostream>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    long long mini,maxi,k;
    long long res_min,res_max;
    maxi=n-m+1;
    k=n%m;
    if(k)
        mini=n/m+1;
    else
        mini=n/m;
    if(k!=0)
        res_min=((mini*(mini-1))/2)*(k)+(((mini-1)*(mini-2))/2)*(m-k);
    else
        res_min=((mini*(mini-1))/2)*(m);
    res_max=((maxi*(maxi-1))/2);
    cout<<res_min<<" "<<res_max;
    return 0;
}
