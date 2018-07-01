#include<iostream>
using namespace std;
struct card
{
    char grp;
    char value;
    int val;
}crd[2];
int main()
{
    char a[]={'6','7','8','9','T','J','Q','K','A'};
    char t;
    int i;
    cin>>t;
    cin>>crd[0].value>>crd[0].grp;
    cin>>crd[1].value>>crd[1].grp;
    for(i=0;i<9;i++)
    {
        if(crd[0].value==a[i])
            crd[0].val=i;
        if(crd[1].value==a[i])
            crd[1].val=i;
    }
    if(crd[0].grp==crd[1].grp)
    {
        if(crd[0].val>crd[1].val)
            cout<<"YES";
        else
            cout<<"NO";
    }
    else
    {
        if(crd[0].grp==t)
            cout<<"YES";
        else if(crd[1].grp==t)
            cout<<"NO";
        else
            cout<<"NO";
    }

}
