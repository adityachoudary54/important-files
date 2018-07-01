#include<iostream>
using namespace std;
int main()
{
    int i,n,a[20],p,q,r;
    cin>>n;
    p=q=r=0;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
        if(i%3==0)
            p+=a[i];
        else if((i-1)%3==0)
            q+=a[i];
        else
            r+=a[i];
    }
    if(p>q)
    {
        if(p>r)
            cout<<"chest";
        else
            cout<<"back";
    }
    else
    {
        if(q>r)
            cout<<"biceps";
        else
            cout<<"back";
    }
}
