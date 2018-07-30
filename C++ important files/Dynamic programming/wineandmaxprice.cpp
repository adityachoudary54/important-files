#include<iostream>
using namespace std;
int price_max_rec(int a[],int i,int j,int t=1)
{
    if((i-j)==0)
    {
        return a[i]*t;
    }
    int tot1,tot2;
    tot1=a[i]*t;
    tot2=a[j]*t;
    //cout<<tot1<<" "<<tot2<<endl;
    tot1+=price_max_rec(a,i+1,j,t+1);
    tot2+=price_max_rec(a,i,j-1,t+1);
    //cout<<tot1<<" "<<tot2<<endl;
    //cout<<t;
    return max(tot1,tot2);
}
int main()
{
    int a[]={2,3,5,1,4};
    cout<<price_max_rec(a,0,4);
    return 0;
}
