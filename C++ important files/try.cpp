#include<iostream>
using namespace std;
int main()
{
    int a,cnt=0;
    cin>>a;
    for(;a!=26;)
    {
        a=(13*a)%64;
        cnt++;
        cout<<cnt<<" "<<a<<endl;
    }
}
