#include<iostream>
using namespace std;
int main()
{
   /* int n,k,p=1,x;
    long long r=0;
    std::cin>>n>>k;
    while(k--)
    {
        std::cin>>x;
        r+=(x-p+n)%n;
        p=x;
    }
    std::cout<<r;*/

    int n,k,next,cur=1;
    long long res=0;
    cin>>n>>k;
    for(int i=0;i<k;i++)
    {
        cin>>next;
        res+=(next-cur+n)%n;//basically hum cycle mein ek jgh se dusri jgh jane ka index nikal rhein hain
        cur=next;
    }
    cout<<res;
    return 0;
}
