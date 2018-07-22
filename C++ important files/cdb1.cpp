#include<iostream>
using namespace std;
int main()
{
    int x=10;
    int &y=x;// y is the reference variable of x
    cout<<y<<endl;
    y++;
    cout<<y<<endl;
    cout<<x<<endl;
    return 0;
}
