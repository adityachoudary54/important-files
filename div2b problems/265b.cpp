#include<iostream>
using namespace std;
int main()
{
    int a[100000],n,cnt=0;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    cnt+=a[0];
    for(int i=0;i<n-1;i++)
    {
        cnt+=((a[i]-a[i+1])>0)?(a[i]-a[i+1]):-(a[i]-a[i+1]);
        cnt++;
        //cout<<cnt;
    }
    cnt+=n;
    cout<<cnt;
}

