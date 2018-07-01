#include<iostream>
using namespace std;
int main()
{
    int a,k,i,n,it;
    cin>>n>>a;
    it=0;
    if((a/n)>2)
        cout<<0;
    else
    {
        k=n;
        while(a!=0)
        {
            if(a/k==2)
                it++;
            a=a-a/k;
            k--;
        }
        cout<<it;
    }
}
