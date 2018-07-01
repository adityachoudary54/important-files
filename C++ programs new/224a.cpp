#include<iostream>
#include<math.h>
using namespace std;
int main()
{
    long double v, a,b,c;
    cin>>a>>b>>c;
    v=a*b*c;
    v=pow(v,0.5);
    cout<<4*((v/a)+(v/b)+(v/c));
}
