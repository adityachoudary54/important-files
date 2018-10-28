#include<iostream>
using namespace std;
int main()
{
    int n,s,t,p[100000+1],step=0;
    cin>>n>>s>>t;
    for(int i=1;i<=n;i++)
    {
        cin>>p[i];
    }
    while(s!=t&&p[s]!=0)
    {
        int temp=p[s];
        p[s]=0;
        s=temp;
        step++;
    }
    //cout<<s<<" "<<t<<" "<<step;
    int val=s==t?step:-1;
    cout<<val;
    return 0;
}
