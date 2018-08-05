#include<iostream>
#include<limits.h>
#include<vector>
using namespace std;
long long int pow(int x,int n)
{
    long long t;
    if(n<=0)
        return 1;
    if(n&1)
    {
        return x*pow(x,n-1);
    }
    else
    {
        t=pow(x,n/2);
        return t*t;
    }
}
int main()
{
    int n,m,k,dif=0,si;
    cin>>n>>m>>k;
    long long int x,y;
    int res=0;
    vector<long long int> v;
    si=m;
    while((si+1)!=0)
    {
        cin>>x;
        v.push_back(x);
        si--;
    }
    for(int i=0;i<m;i++)
    {
        x=v[i];
        y=v[m];
        //cout<<x<<" "<<y;
        while((x!=0)&&(y!=0))
        {
            if((x&1)!=(y&1))
            {
                res++;
            }
            x=x>>1;
            y=y>>1;
        }
        if(x==0)
        {
            while(y!=0)
            {
                if(y&1)
                    res++;
                y=y>>1;
            }
        }
        else if(y==0)
        {
            while(x!=0)
            {
                if(x&1)
                    res++;
                x=x>>1;
            }
        }
        //cout<<x<<" "<<y<<" "<<res<<" "<<k<<endl;
        //cout<<endl;
        if(res<=k)
            dif++;
        res=0;
    }
    cout<<dif;
    return 0;
}
