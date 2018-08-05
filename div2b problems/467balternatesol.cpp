#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int n,m,k,res,diff=0,si;
    int x;
    vector<int> v;
    cin>>n>>m>>k;
    si=m;
    while((si+1)!=0)
    {
        cin>>x;
        v.push_back(x);
        si--;
    }
    for(int i=0;i<m;i++)
    {
        res=v[i]^v[m];
        int t=0;
        while(res!=0)
        {
            if(res&1)
                t++;
            res>>=1;
        }
        if(t<=k)
            diff++;
    }
    cout<<diff;
}
