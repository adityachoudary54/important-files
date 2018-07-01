#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int n[50],m,k,i,avl,sum,num;
    cin>>num>>m>>k;
    sum=0;
    for(i=0;i<num;i++)
        cin>>n[i];
    sort(n,n+num);
    i=num-1;
    if(k>=m)
    {
        cout<<"0";
        return 0;
    }
    k--;
    while(i>=0)
    {
        sum=sum+n[i];
        avl=sum+k;
        if(avl>=m)
        {
            cout<<num-i;
            return 0;
        }
        else
        {
            k--;
            i--;
        }
    }
    cout<<-1;
    return 0;
}
