#include<iostream>
using namespace std;
int main()
{
    int a,cnt=0;
    cin>>a;
    for(;a!=1||cnt<=63;)
    {
        a=(5*a+63)%64;
        cout<<cnt++<<" "<<a<<endl;
    }
}
