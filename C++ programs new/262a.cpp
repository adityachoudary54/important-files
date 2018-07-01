#include<iostream>
using namespace std;
int main()
{
    int i,j,n,k,t,u;
    t=0;
    string a[100];
    cin>>n>>k;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(i=0;i<n;i++)
    {   u=0;
        if(a[i].size()<=k)
        {
            t++;
        }
        else
        {
            for(j=0;j<a[i].size();j++)
            {
                if(a[i][j]=='4'||a[i][j]=='7')
                    u++;
            }
            if(u<=k)
                t++;
        }
    }
    cout<<t;
}
