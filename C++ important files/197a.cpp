#include<iostream>
using namespace std;
int main()
{
    int a,b,r;
    cin>>a>>b>>r;
    if((a<=b&&(2*r>a))||(a>=b&&(2*r>b)))
        cout<<"Second";
    else
        cout<<"First";
    return 0;
}
